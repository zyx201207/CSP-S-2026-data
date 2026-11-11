#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],ans[300010];
void dfs(int i){
	int mp[m+5];
	memset(mp,0,m+2);
	for(int j=n;j>=i;j--){
		if(!mp[a[j]])mp[a[j]]=j;
		else{
			int jj=mp[a[j]];
			for(int z=jj;z<=n;z++)ans[a[z]]++;
			return ;
		}
	}for(int j=i;j<=n;j++)ans[a[j]]++;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		dfs(i);
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
