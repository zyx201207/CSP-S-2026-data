#include<bits/stdc++.h>
using namespace std;
bool v[1001000];
int n,m,a[1001000],d[1001000],mx=-1;
void dfs(int x=1){
	if(x-1==m){
		int s=d[1];
		for(int i=2;i<=m;i++){
			s=s&d[i];
		}
		mx=max(mx,s);
		return;
	}
	for(int i=1;i<=n;i++){
		if(!v[i]){
			d[x]=a[i],v[i]=true;
			dfs(x+1);
			d[x]=0,v[i]=false;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs();
	cout<<mx;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
