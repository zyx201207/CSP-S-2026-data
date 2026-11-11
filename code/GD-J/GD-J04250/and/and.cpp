#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[300005];
bool lok[300005];
int maxx=-1;
void dfs(int c,long long s){
	if(c==m){
		if(s>maxx)maxx=s;
		return ;
	}
	for(int j=1;j<=n;j++){
		if(lok[j])continue;
		lok[j]=1;
		dfs(c+1,s&a[j]);
	}
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		dfs(1,a[i]);
	}
	cout<<maxx;
	
}
