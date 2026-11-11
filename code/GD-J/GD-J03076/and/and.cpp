#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N];
int ans=INT_MAX;
vector<int>v[40];
int lowbit(int x){
	return x&-x;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m; cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x,pos; cin>>x;
		a[i]=x;
		int lst=0,num=0;
		while(x){
			pos=lowbit(x);
			while(1){
				pos/=2;
				num++;
				if(pos<=lst) break;
			}
			lst=lowbit(x);
			x-=lst;
			v[num].push_back(a[i]);
		}
	}
	int pos=0;
	for(int i=34;i>=0;i--){
		if(v[i].size()>=m){
			pos=i;
			break;
		}
	}
	sort(v[pos].begin(),v[pos].end());
	ans=v[pos][v[pos].size()-1];
	for(int i=1;i<=m;i++){
		ans=ans&v[pos][v[pos].size()-i];
	}
	cout<<ans;
	return 0;
}
