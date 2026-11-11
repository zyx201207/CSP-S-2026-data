//100 at 14:46
#include<bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define PIL pair<int,ll>
#define PLI pair<ll,int>
#define fi first
#define se second 
using ll=long long;
using ull=unsigned long long;
using ld=long double;
#define FILE "crystal"
// #define FOR_ONLINE
// #define TEST_FOR_MS
// #define freopen(x) feropen(x)
bool mst;
const int N=5e5+5;
ll n,m,a[N],S[N],ans;
void Main(){
	cin>>n>>m;ans=0;
	for(int i=1;i<=n;i++)   cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)   S[i]=S[i-1]+a[i];
	for(int i=1;i<=n;i++){
		ll l=1,r=i;
		while(l<r){
			ll mid=(l+r)>>1;
			if(a[i]*(i-mid+1)-(S[i]-S[mid-1])>m)    l=mid+1;
			else    r=mid;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans<<"\n";
}
bool med;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
#ifndef FOR_ONLINE
#ifndef TEST_FOR_MS
	freopen(FILE".in","r",stdin);
	freopen(FILE".out","w",stdout);
#else
	string x;cin>>x;
	freopen(("down/"FILE"/"FILE+x+".in").c_str(),"r",stdin);
	freopen(FILE".out","w",stdout);
#endif
#endif
	cerr<<fixed<<setprecision(6)<<abs(&med-&mst)/1024.0/1024<<"MB\n";
	double st=clock();
	Main();
	cerr<<fixed<<setprecision(6)<<(clock()-st)/CLOCKS_PER_SEC<<"s\n";
}
/*
WorldMachine suki
*/