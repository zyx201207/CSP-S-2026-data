#include <bits/stdc++.h>
using namespace std;
#define int long long
#define maxn 5005
int g[maxn][maxn],cnt[maxn][maxn],a[maxn],n,d;
int abss(int x){
	if(x<0) return -x;
	return x;
}
void solve(){
	cin >> n >> d;
	memset(g,0x3f,sizeof(g));
	memset(cnt,0,sizeof(cnt));
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cnt[i][j]=1;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(abss(a[i]-a[j])<=d) g[i][j]=1;
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j||i==k||j==k) continue;
				int res=g[i][k]+g[k][j];
				if(res<g[i][j]) cnt[i][j]=1,g[i][j]=res;
				else if(res==g[i][j]) cnt[i][j]++;
			}
		}
	}
	int sum=0;
	for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) if(cnt[i][j]==2){
		sum++;
		//cout << g[i][j] << " " << i << " " << j << "\n";
	}
	cout << sum << endl;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int t,c;
	cin >> c >> t;
	while(t--) solve();
	return 0;
}
