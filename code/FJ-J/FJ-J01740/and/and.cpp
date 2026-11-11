#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m;
int a[2*N];
int v[2*N];
int maxx=-1;
void dfs(int depth,int js){
	if(depth==m){
		maxx=max(maxx,js);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!v[i]){
			v[i]=1;
			if(js==0) dfs(depth+1,a[i]);
			else dfs(depth+1,js&a[i]);
			v[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	int pmax=a[1];
	int js=a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i];
		js&=a[i];
		pmax=max(pmax,a[i]);
	}
	if(m==1){
		cout<<pmax;
		return 0;
	}
	if(m==n){
		cout<<js;
		return 0;
	}
	
	dfs(0,0);
	cout<<maxx;
	return 0;
}
