#include<bits/stdc++.h>
using namespace std;
int a[200050],n,m;
long long maxn=0;
bool cmp(int x,int y){
	return x>y;
}
bool v[200050];
void dfs(int x,long long ans){
	if(x==m){
		maxn=max(maxn,ans);
		return;
	} 
	for(int i=1;i<=max(m*2,n);i++){
		if(v[i]==0){
			v[i]=1;
			if(x==0)dfs(x+1,a[i]);
			else dfs(x+1,ans&a[i]);
			v[i]=0;
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	dfs(0,0);
	
	cout<<maxn;
} 
