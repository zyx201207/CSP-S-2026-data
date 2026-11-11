#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[511111],s[511111],ans[511111],vis[511111],mps[511111];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for (int i=1;i<=n;i++){
		cin >> a[i];
	}
	for (int i=1;i<=n;i++){
		int k=1;
		memset(s,0,sizeof(s));
		memset(vis,0,sizeof(vis));
		memset(mps,0,sizeof(mps));
		for (int j=i;j<=n;j++){
			if (vis[a[j]]==1){
				int f=0;
				for (int p=1;p<k;p++){
					if (s[p]==a[j] && mps[p]==0){
						f=1;
					}
					if (f==1 && vis[s[p]]>0 && mps[p]==0){
						mps[p]=1;
						vis[s[p]]--;
					}
				}
			}
			vis[a[j]]++;
			s[k]=a[j];
			k++;
		}
		for (int i=1;i<=m;i++){
			if (vis[i]>0){
				ans[i]++;
			}
		}
	}
	for (int i=1;i<=m;i++){
		cout << ans[i] << " ";
	}
	return 0;
}
