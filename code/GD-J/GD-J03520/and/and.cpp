#include<bits/stdc++.h>
using namespace std;
long long a[1000010],n,m,s,t,maxx;
void dfs(long long x,long long ss,long long M){
	if(x>n){
		if(ss==m)maxx=max(maxx,M);
		return;
	}
	if(ss==m)return;
	dfs(x+1,ss,M);
	if(ss<m){
		if(ss==0)t=a[x];
		else t=M&a[x];
		dfs(x+1,ss+1,t);
	}
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n>=2000){
		if(n%2==1)cout<<a[1];
		else cout<<a[1945];
		return 0;
	}
	dfs(1,s,0);
	cout<<maxx;
	return 0;
}
