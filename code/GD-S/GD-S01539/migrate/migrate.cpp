#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 2000010
#define inf 1000000000000000ll
int C;
int n,d;
int a[N];

int dp[N],num[N];
int fr[N];
void solve1(){
	for(int i=1;i<=n;i++)dp[i]=inf,num[i]=0,fr[i]=0;
	
	a[0]=-inf;a[n+1]=inf;
	for(int i=2;i<=n;i++)if(a[i]-a[i-1]<=d&&a[i]-a[i-2]>d&&a[i+1]-a[i-1]>d)fr[i]+=fr[i-1]+1;
	
	int ans=0;
	for(int i=2;i<=n;i++){
		int id1=lower_bound(a+1,a+n+1,a[i]-d)-a;
		if(id1==i)continue;
		int id2=id1+1;
		if(id2==i)continue;
		int id3=lower_bound(a+1,a+n+1,a[id2]-d)-a;
		if(id3==id1)continue;
		if(id2+1!=i&&a[id2+1]-a[id3]<=d)continue;
		ans+=fr[id3]+1;
	}
	
	cout<<ans<<'\n';
}
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>a[i];
	
	solve1();
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T;cin>>C>>T;
	while(T--)solve();
	
	return 0;
}
