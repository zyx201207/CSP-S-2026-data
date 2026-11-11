#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
const int N=7e4+5;
long long n,m;
long long a[N],f[N];
long long dfs(int u,int s){
	if(s==0)return 2147483647;
	if(u>n)return 0;
	if(f[u])return f[u];
	long long t=max(dfs(u+1,s),dfs(u+1,s-1)&a[u]);
	return t;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<dfs(1,m);
	return 0;
}

