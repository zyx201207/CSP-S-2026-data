#include <iostream>
#include <cstdio>
#define int long long
using namespace std;
long long c,t,n,d;
/*
int pre[2000010],nxt[2000010],pl[2000010],pr[2000010];
int p1[2000010],p2[2000010];
*/
int dp[5010],p[5010];
long long x[2000010];
signed main(void) {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> c >> t;
	for (;t--;) {
		cin >> n >> d;
		for (int i=1;i<=n;i++) cin >> x[i];
		int ans=0;
		for (int i=1;i<=n;i++) {
			for (int j=i;j<=n;j++) {
				dp[j]=p[j]=0;
			}
			int sum=1,l=i,r=i;
			dp[i]=1;
			p[i]=1;
			for (int j=i+1;j<=n;j++) {
				if (x[j]-x[j-1]>d) break;
				for (;x[j]-x[l]>d;) {
					sum-=dp[l];
					l++;
				}
				for (;p[r+1]==p[l];) {
					r++;
					sum+=dp[r];
//					cout << j << " " << r << " " << dp[r] << endl;
				}
				if (sum<=2) 
				dp[j]=sum;
				else dp[j]=3;
				p[j]=p[l]+1;
//				cout << i << " " << j << " " << dp[j] << " " << p[j] << " " << l << " " << r << endl;
				if (dp[j]==2) {
					ans++;
//					cout << i << " " << j << endl;
				}
			}
		}
		cout << ans << endl;
		/*
		for (int i=1;i<=n;i++) pre[i]=nxt[i]=pl[i]=pr[i]=p1[i]=p2[i]=0;
		long long lid=1;
		for (int i=1;i<=n;i++) {
			for (;x[i]-x[lid]>d;) {
				lid++;
			}
			pre[i]=lid;
			p1[pre[i]]++;
		}
		long long rid=n;
		for (int i=n;i>=1;i--) {
			for (;x[rid]-x[i]>d;) {
				rid--;
			}
			nxt[i]=rid;
			p2[nxt[i]]++;
		}
		for (int i=1;i<=n;i++)
			pl[i]=pl[pre[i]]+1;
		for (int i=n;i>=1;i--)
			pr[i]=pr[nxt[i]]+1;
		long long ans=0;
		for (int i=3;i<=n-1;i++) {
//			cout << i << " " << i-1 << " " << pre[i] << " " << pre[i-1] << " " << nxt[i] << " " << nxt[i-1] << " ";
			if (pre[i]==pre[i-1]&&nxt[i]==nxt[i-1]&&pre[nxt[i-1]]==i-1&&nxt[pre[i]]==i)
				ans+=1ll*(pl[pre[i]])*(pr[nxt[i]])-1;
//			cout << endl;
//			ans+=1ll*(min(nxt[i],nxt[i-1])*1ll-i)*(i-1-max(pre[i],pre[i-1]));
			ans+=1ll*p1[i-1]*p2[i];
			cout << p1[i-1] << " " << p2[i] << endl;
//			cout << (min(nxt[i],nxt[i-1])-i) << " " << (i-1-max(pre[i],pre[i-1])) << " " << nxt[i] << " " << nxt[i-1] << " " << pre[i] << " " << pre[i-1] << " " << i << endl;
		}
		cout << ans << "\n";*/
	}
	return 0;
}
