#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i = (x);i <= (y);i++)
#define dow(i,x,y) for(int i = (x);i >= (y);i--)
#define rec(i,x,y) for(int i = (x);i;i = (y))
#define int long long
#define ull unsigned long long
#define fi first
#define se second
#define mt empty
#define siz(x) x.size()
#define fil(x,y) memeset(x,y,sizeof(x))
#define ciallo return 0;
#define N 500005
#define mod 998244353
int n,m,a[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n >> m;
	rep(i,1,n){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	int ans = 0;
	rep(i,1,n){
		int cnt = 0,l = 0,s =0;
		dow(j,i-1,1){s += a[i] - a[j];
			cnt += s;
			if(cnt >= m){l = j;break;}
			
		}
		ans = max(ans,i-l+1);
	}
	cout << ans << endl;
	ciallo
}
