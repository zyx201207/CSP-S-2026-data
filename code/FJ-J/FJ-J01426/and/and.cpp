#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m;
int a[N];
string s[N];
int sga,vis[N];
void dfs(int x,int sum){
	if(x>m){
		sga=std::max(sga,sum);
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			if(x==1){
				dfs(x+1,a[i]);
			}
			dfs(x+1,sum&a[i]);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+n+1);
	if(n<=20){
		dfs(1,0);
		cout<<sga;
		return 0;
	}
	if(m==n){
		sga=a[1];
		for(int i=1;i<=n;i++){
			sga&=a[i];
		}cout<<sga;
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			sga=max(sga,a[i]);
		}cout<<sga;
	}
	sga=a[n];
	for(int i=n;i>n-m;i--){
		sga&=a[i];
	}cout<<sga;
	return 0;
}
