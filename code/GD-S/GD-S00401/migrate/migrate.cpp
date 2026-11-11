#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pb push_back
const int N=2e6+10;
const ll inf=0x3f3f3f3f3f3f3f3f;
const ll MOD=998244353;
ll n,d,x[N],l[N],r[N],f[N],g[N],s[N],cnt[N],a[N],b[N];
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>x[i],a[i]=b[i]=s[i]=0;
	l[0]=1;
	for(int i=1;i<=n;i++){
		l[i]=l[i-1];
		while(x[i]-x[l[i]]>d)l[i]++;
	}
	r[n+1]=n;
	for(int i=n;i>=1;i--){
		r[i]=r[i+1];
		while(x[r[i]]-x[i]>d)r[i]--;
	}
	for(int i=1;i<=n;i++)cnt[i]=0;
	for(int i=1,lst=1;i<=n;i++){
		cnt[i]=1;
		if(i&&i==r[i-1])cnt[i]+=cnt[i-1];
		f[i]=cnt[i];
		if(i>1&&i<n&&x[i+1]-x[i-1]>d)f[i]=i-lst+1;
		if(i==n)f[i]=i-lst+1;
		if(x[i+1]-x[i]>d)lst=i+1;
		if(r[i]-i>=2)a[i+2]+=f[i],b[r[i]-1]+=f[i];
		if(r[i]-i==2)s[r[i]]+=f[i];
	}
	for(int i=1;i<=n;i++)cnt[i]=0,s[i]+=s[i-1];
	for(int i=n,lst=n;i>=1;i--){
		cnt[i]=1;
		if(i<n&&i==l[i+1])cnt[i]+=cnt[i+1];
		g[i]=cnt[i];
		if(i>1&&i<n&&x[i+1]-x[i-1]>d)g[i]=lst-i+1;
		if(i==1)g[i]=lst-i+1;
		if(x[i]-x[i-1]>d)lst=i-1;
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		if(i-l[i]>=2){
			ll sum=a[l[i]+1]+b[i-2];
			if(i-l[i]==2)sum>>=1;
			if(l[i]+2<=i-2)sum+=(s[i-2]-s[l[i]+1]);
			ans+=(sum*g[i]);
		}
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	ll C,T;
	cin>>C>>T;
	while(T--)solve();
	return 0;
} 
