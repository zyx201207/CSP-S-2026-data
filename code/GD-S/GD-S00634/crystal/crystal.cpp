#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define freop(s) freopen(s".in","r",stdin);freopen(s".out","w",stdout);
#define endl '\n'
#define inf 0x7f7f7f7f
#define lb(x) ((x)&-(x))
#define pii pair<int,int>
#define fir first
#define sec second
#define mkp make_pair
const int N=5e5+5;
int n,m,ans;ll a[N],sm[N];

int main(){
	cin.tie(0)->ios::sync_with_stdio(0);
	cout.tie(0);
	freop("crystal");
//↑以上为初始化↑
//-------------------------------------------------
	cin >> n >> m;
	for(int i = 1;i<=n;++i) cin >> a[i];
	sort(a+1,a+n+1);
	for(int i = 1;i<=n;++i) sm[i]=sm[i-1]+a[i];
	for(int i = 1;i<=n;++i){
		int l=1,r=i,mid;
		while(l<r){
			mid=(l+r)>>1;
			if(a[i]*(i-mid+1)-(sm[i]-sm[mid-1])<=m) r=mid;
			else l=mid+1;
		}
		ans=max(ans,i-l+1);
	}
	cout << ans << endl;
	return 0;
}

