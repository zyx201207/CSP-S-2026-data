#include<bits/stdc++.h>
using namespace std;
int a[2000],n,m,ans=-1e9;
int b[2000];
void dfs(int x){
	if (x==m){
		int u=a[0];
		for (int i=1;i<m;i++) u&=a[i];
		ans=max(ans,u);
		return ;
	}
	for (int i=0;i<n;i++){
		bool apple=1;
		for (int j=0;j<x;j++){
			if (b[i]==a[j]){
				apple=0;
				break;
			}
		}
		if (apple){
			a[x]=b[i];
			dfs(x+1);
		}
	}
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);   
	cin>>n>>m;
	for (int i=0;i<n;i++) cin>>b[i];
	dfs(0);
	cout<<ans;
} 
