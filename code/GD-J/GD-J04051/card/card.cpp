#include <bits/stdc++.h>
using namespace std;
int a[500010],n,m,ans[200010],num[5010],cnt[3010];
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) {
		int w=0;
		memset(num,0,sizeof num),memset(cnt,0,sizeof cnt);
		for(int j=i;j<=n;j++) {
			cnt[a[j]]++;
			if(cnt[a[j]]==2) {
				while(num[w]!=a[j]) cnt[num[w]]--,num[w]=0,w--;
				num[w]=0,w--;cnt[a[j]]=1;
			}num[++w]=a[j];
		}
		for(int i=1;i<=w;i++) ans[num[i]]++;
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
}
