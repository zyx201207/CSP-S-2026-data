#include<bits/stdc++.h>
using namespace std;
int n,m,a[200009],s,v[200009],choose[200009],maxn=0;
void dfs(int k){
	if(k>m){
		s=choose[1];
		for(int i=2;i<=m;i++)  s=s&choose[i];
		maxn=max(maxn,s);
	}
	for(int i=k;i<=n;i++){
		if(v[i]==0){
			v[i]=1;
			a[k]=i;
			dfs(k+1);
			v[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(1);
	cout<<maxn;
	return 0; 
}
