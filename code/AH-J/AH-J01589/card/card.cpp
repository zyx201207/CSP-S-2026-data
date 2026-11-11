#include<bits/stdc++.h>
using namespace std;
int pos[500005],card[500005];
int ans[300005],a[500005];
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=n;i++) {
		int cnt=0;
		for (int j=i;j<=n;j++) {
			if (pos[a[i]]==0) pos[a[i]]=++cnt;
			else cnt=pos[a[i]];
			card[cnt]=a[i];
		}
		for (int i=1;i<=cnt;i++)ans[card[i]]++;
		for (int i=1;i<=n;i++) pos[i]=0,card[i]=0;
	}
	for (int i=1;i<=m;i++) cout<<ans[i]<<" ";
}
