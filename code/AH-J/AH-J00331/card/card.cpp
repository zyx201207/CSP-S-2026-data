#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[300005],ttt[300005],len,vis[300005];
void game(int ll){
	memset(vis,0,sizeof(vis));
	len=0;
	for(int i=ll;i<=n;i++){
		if(vis[a[i]]==0)vis[a[i]]++,len++,ttt[len]=a[i];
		else{
			int t;
			for(int j=1;j<=len;j++)
				if(ttt[j]==a[i])t=j;
			for(int j=t+1;j<=len;j++)vis[ttt[j]]--;
			len=t;
		}
	}
	for(int i=1;i<=m;i++)
		if(vis[i])ans[i]++;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	if(m==1){
		cout<<1;
		return 0;
	}
	for(int i=1;i<=n;i++)game(i);
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
}
