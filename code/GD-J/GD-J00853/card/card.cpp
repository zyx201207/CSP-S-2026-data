#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=3e5+10;
int t[M];
int t1[N];
int a[N];
int stk[M];
int f[N];
int n,m;
void dfs(int u){
	if(u==n){
		t[a[u]]++;
		return;
	}
	if(f[u]==0){
		t[a[u]]++;
		dfs(u+1);
	}
	else {
		dfs(f[u]);
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		f[t1[a[i]]]=i;
		t1[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		dfs(i);
	}
	for(int i=1;i<=m;i++){
		cout<<t[i]<<' ';
	}
	return 0;
}

