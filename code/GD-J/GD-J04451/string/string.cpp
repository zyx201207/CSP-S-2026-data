#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
vector<ll> p(2e5+10);
vector<char> q(2e5+10);
ll sum,ab,pp=1;
vector<char>a;
void dfs(){
	for(ll i=1,j=pp;i<=pp/2;i++,j--){
		if(a[i]!=a[j])sum++;
	} 
	cout<<sum; 
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n;
	
	if(n==1){
		cout<<"0";
		return 0;
	}
	
	for(int i=1;i<=n;i++){
		cin>>p[i]>>q[i];
	}
	
	if(n==2){
		if(q[1]==q[2])cout<<"0";
		else cout<<min(p[1],p[2]);
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=p[i];j++){
			a[pp]=q[i];
			pp++; 
		}
	}
	dfs();
	return 0;
} 

