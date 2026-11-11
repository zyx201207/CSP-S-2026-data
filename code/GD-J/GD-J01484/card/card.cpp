#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=500005;
const int M=300005;
int n,m,al;
int a[N],ans[N];
int vis[N] {0};
//bool cnt[N] {0};

signed main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
//		if(cnt[a[i]]==0) {
//			al++;
//			cnt[a[i]]==1;
//		}
	}
	for(int i=1;i<=n;i++) {
		memset(vis,0,sizeof(vis));
//		for(int i=1;i<=al;i++) {
//			cout<<ans[i]<<" ";
//		}
//		cout<<endl;
		for(int j=i;j<=n;j++) {
			if(vis[a[j]]>0) {
				for(int p=vis[a[j]];p<j;p++) {
					if(vis[a[p]]!=0) {
						vis[a[p]]=0;
						ans[a[p]]--;
					}
				}
				vis[a[j]]=j;
				ans[a[j]]++;
			}else {
				vis[a[j]]=j;
				ans[a[j]]++;
			}
		}
	}
	int i=1;
	while(ans[i]!=0) {
		cout<<ans[i]<<" ";
		i++;
	}
	return 0;
} 
