#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],b[200005],d[200005];
int ans;
void dfs(int s,int x){
	if(d[x]>=s){
		return;
	}
	d[x]=s;
	if(x==m){
		ans=max(ans,s);
	}
	for(int i=1;i<=n;i++){
		if(b[i]==0){
			b[i]=1;
			dfs((s&a[i]),x+1);
			b[i]=0;
		}
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
	for(int i=1;i<=n;i++){
		b[i]=1;
		dfs(a[i],1);
		b[i]=0;
	}
	cout<<ans;

	return 0;
}
/*
5 3
31 3 1 15 7
*/
