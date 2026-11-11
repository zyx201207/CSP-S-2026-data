#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+10;
int n,prt=0,sft=0;
ll a[N],s[N];
ll pra[N],sfa[N],prc[N],sfc[N];
char c[N];
void file() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
} 
void fodd() {
	for(int i=1;i<=n;i++) s[i] = s[i-1]+a[i];	
	if(!(s[n]&1)) return; 
	ll mid=s[n]/2+1;
	int cut=n+1;
	for(int i=1;i<=n;i++)
		if(s[i]>mid) {
			cut = i;
			break;
		}
	a[cut]--;
	//printf("[Debug] is odd! a[%d]--! mid = %lld!\n",cut,mid);
}
void solve() {
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i] >> c[i];
	s[0] = 0;
	fodd();
	s[0] = 0;
	for(int i=1;i<=n;i++) s[i] = s[i-1]+a[i];
	//for(int i=1;i<=n;i++) printf("[Debug] s[%d] = %lld \n",i,s[i]);
	
	ll mid=s[n]/2;
	int cut=n+1;
	bool zqie = false;
	for(int i=1;i<=n;i++) {
		if(s[i]>mid) {
			cut = i;
			break;
		}
		if(s[i]==mid) { 
			cut  = i+1;
			zqie = true;
			break;
		}
	}
	for(int i=1;i<=cut-1;i++) (pra[++prt]=a[i], prc[prt]=c[i]);
	if(zqie) {
		for(int i=n;i>=cut;i--) (sfa[++sft]=a[i], sfc[sft]=c[i]);
	} else {
		sft++;
		for(int i=n;i>=cut+1;i--) (sfa[++sft]=a[i], sfc[sft]=c[i]);
		pra[++prt] = mid-s[cut-1];
		prc[prt]   = c[cut];
		sfa[++sft] = a[cut]-pra[cut];
		sfc[sft]   = c[cut];
	}
	// printf("[Debug] cut=%d, mid=%lld\n",cut,mid);
	// for(int i=1;i<=prt;i++) printf("[Debug] in %d : pra=%lld, prc=%c \n",i,pra[i],prc[i]);
	// for(int i=1;i<=sft;i++) printf("[Debug] in %d : sfa=%lld, sfc=%c \n",i,sfa[i],sfc[i]);
	// printf("[Debug] is ÕûÇÐ: %s\n",((zqie)?"yes":"no"));
	
	ll ans=0, pc=pra[1], sc=sfa[1];
	for(int i=1,j=1;i<=prt&&j<=sft;) {
		if(pc<=0) (i++, pc=pra[i]);
		if(sc<=0) (j++, sc=sfa[j]);
		ll mn = min(pc,sc);
		pc -= mn;
		sc -= mn;
		if(prc[i]==sfc[j]) continue;
		ans += mn;
	}
	cout << ans << '\n';
}
int main() {
	file();
	int t=1;
	// cin >> t;
	while(t--) solve();
}
