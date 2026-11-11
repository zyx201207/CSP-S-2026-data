#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=4e5;
int a[N],n,m;
ll ans=0;
void sol(ll mx){
	if(mx<0) return ;
	vector<int>v[66];
	for(int i=1;i<=n;i++)
		for(int j=0;(1<<j)<=a[i];j++)
			if((1<<j)&a[i])
				v[j].push_back(a[i]);
	for(int i=mx;i>=0;i--){
		if(v[i].size()>=m){
			for(int j=0;j<v[i].size();j++) a[j+1]=v[i][j];
			ans+=1<<i,n=v[i].size(),sol(i-1);
			break;
		}
	}
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	vector<int>v[66];
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=0;(1<<j)<=a[i];j++){
			if((1<<j)&a[i])
				v[j].push_back(a[i]);
		}
	}
	for(int i=33;i>=0;i--){
		if(v[i].size()>=m){
			for(int j=0;j<v[i].size();j++) a[j+1]=v[i][j];
			ans+=1<<i,n=v[i].size(),sol(i-1);
			break;
		}
	}
	cout<<ans;
	return 0;
} 
