#include<bits/stdc++.h>
#define ll long long
#define db double
#define bint __int128
#define pii pair<int,int>
#define fi first
#define se second
#define mkp make_pair
#define gc getchar
#define chkmax(a,b) a=max(a,b)
#define chkmin(a,b) a=min(a,b)
#define debug(x) cerr<<#x<<" = "<<x<<endl
using namespace std;
int ret(); bool vst;
const int N=5e5+5,mod=998244353;
int n;ll m;
ll a[N];
void sol(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	ll j=1,s=0,c=1,ans=0;
	for(int i=1;i<=n;){
		while(j<i && s>m)
			c--,s-=a[i]-a[j],j++;
		chkmax(ans,c),i++,c++;
		s+=(c-1)*(a[i]-a[i-1]);
	}
	cout<<ans<<endl;
}
bool ved; int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	sol();
	return ret();
}
int ret(){cerr<<"Space used: "<<abs((&vst)-(&ved))/1024.0/1024.0<<" MB."<<endl; return 0;}
