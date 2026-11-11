#include <bits/stdc++.h>
using namespace std;
int n,m;
int card[5010];
int ans[3010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>card[i];
	for(int i=1;i<=n;i++){
		bool vis[3010];
		int s[3020],cnt;
		memset(s,0,sizeof s);
		for(int j=i;j<=n;j++){
			if(!vis[card[j]]){
				s[++cnt]=card[j];
				vis[card[j]]=1;
			}else{
				while(s[cnt]!=card[j]){
					vis[s[cnt]]=0;
					s[cnt]=0,cnt--;
				}
			}
		}
		for(int j=1;j<=m;j++)ans[j]+=vis[j];
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
