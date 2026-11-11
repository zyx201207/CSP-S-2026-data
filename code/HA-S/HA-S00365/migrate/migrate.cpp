#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define pb push_back
#define fi first
#define se second
using namespace std;
const int N=5e5+10;
const int M=5e3+10;
const int mod=998244353;
const ll inf=0x3f3f3f3f3f3f3f3f;
int maxx=N-10;
ll n,m,ans,cnt,d,T;
ll a[N],b[M][M];
ll read(){ll x=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
ll ppow(ll n,ll m){ll s=1;while(m){if(m&1)s=(s*n)%mod;n=(n*n)%mod;m>>=1;}return s;}
void solve(){
	cin>>n>>d;
	memset(b,0x3f,sizeof b);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i][i]=0;
	}
	for(int i=1;i<=n;i++){
		for(int x=i-1;x>=1;x--){
			for(int y=x;y<=i;y++){
				if(a[y]-a[x]>d||b[y][i]==inf)continue;
				else {
					b[x][i]=min(b[x][i],1+b[y][i]);
				}
			}
//			cout<<x<<' '<<i<<' '<<b[x][i]<<'\n';
		}
	}
	ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			if(b[j][i]==inf||b[j][i]==1||!b[j][i])continue;
			ll cnt=0;
			for(int x=j+1;x<i;x++){
				if(b[j][i]==b[j][x]+b[x][i]){
					cnt++;
				}
			}
			if(cnt==2){
				ans++;
			}
		}
	}
	cout<<ans<<'\n';
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	read();
	for(int i=read();i;i--){
		solve();
	}
}
