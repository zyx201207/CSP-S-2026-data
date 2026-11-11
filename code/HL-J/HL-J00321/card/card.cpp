#include <bits/stdc++.h>
using namespace std;
int n,m;
long long a[500005],b[500005],cnt[500005],x,cnt2[500005];
int main() {
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i = 1;i<=n;i++) {
    	cin>>a[i];
	}
	for(int i = 1;i<=n;i++) {
		memset(b,0,sizeof(b));
		memset(cnt,0,sizeof(cnt));
		for(int j = i;j<=n;j++) {
			if(cnt[a[j]]==0) {
				cnt[a[j]] = x+1;
				b[++x] = a[j];
			}else {
				for(int k = cnt[a[j]]+1;k<=x;k++) {
					cnt[b[k]] = 0;
					b[k] = 0;
				}
				x = cnt[a[j]];
			}
		}
		for(int i = 1;i<=m;i++) {
			if(cnt[i] != 0) cnt2[i]++;
		}
	}
	for(int i = 1;i<=m;i++) {
		cout<<cnt2[i]<<" ";
	}
    return 0;
}
