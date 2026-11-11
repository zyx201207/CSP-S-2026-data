#include "bits/stdc++.h"
using namespace std;
int n,m;
int a[500005],c[500005],siz[500005],lst[500005],answer[500005];
vector<int> son[500005];
void dfs(int x){
	siz[x]=1;
	for(int i:son[x]) dfs(i),siz[x]+=siz[i];
}
int main(void){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	reverse(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		if(!lst[a[i]]){
			lst[a[i]]=i;
			son[i-1].push_back(i);
			c[i]=a[i];
		}else{
			son[lst[a[i]]].push_back(i);
			c[i]=0;
			lst[a[i]]=i;
		}
	dfs(0);
	for(int i=1;i<=n;i++)
		if(c[i]) answer[c[i]]=siz[i];
	for(int i=1;i<=m;i++) cout<<answer[i]<<" ";
	fclose(stdin);
	fclose(stdout);
}
