#include<bits/stdc++.h>
using namespace std;
const int N=5e5+1,M=3e5+1;
int a[N],card[N],vis[N],ans[M],cnt[2];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,cnt=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n<=1)for(int i=1;i<=n;i++){
		cnt=0;
		memset(vis,0,sizeof(vis));
		for(int j=i;j<=n;j++){
			if(vis[a[j]]){
				for(int k=vis[a[j]]+1;k<=cnt;k++)
					vis[card[k]]=card[k]=0;
				cnt=vis[a[j]];
			}
			else card[++cnt]=a[j],vis[a[j]]=cnt;
		}
		for(int j=1;j<=m;j++)
			if(vis[j])ans[j]++;
	}
	if(m<=2){
		if(m==1){cout<<n;return 0;}
		for(int i=1;i<=n;i++)::cnt[a[i]]++;
		if(a[n]==1)ans[1]=n,ans[2]=::cnt[2];
		else ans[2]=n,ans[1]=::cnt[1];
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
}
