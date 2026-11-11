#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int N=2e6+7;
const int N=5007, inf=0x3f3f3f3f;
int n;ll d;
ll a[N];
int dis[N][N], cnt[N][N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, T;
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j]=(i==j?0:inf), cnt[i][j]=0;
		int pos=1, ans=0;
		for(int i=2;i<=n;i++){
			while(a[i]-a[pos]>d) ++pos;
			for(int j=pos;j<i;j++)
				dis[j][i]=cnt[j][i]=1;
			for(int j=1;j<pos;j++){
				if(dis[j][pos]==inf) continue;
				int CNT=0, lim=dis[j][pos];
				for(int k=pos;k<i && dis[j][k]==lim && CNT<=2;k++)
					CNT+=cnt[j][k];
				cnt[j][i]=CNT;
				dis[j][i]=lim+1;
				if(CNT==2) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}