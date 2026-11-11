#include <bits/stdc++.h>
#define fs first
#define sc second
#define int long long
#define vi vector<int> 
#define For(i,x,y) for(int i = x;i <= y;i ++)
#define For_(i,x,y) for(int i = x;i <= y;i ++)
#define pb push_back
#define endl '\n'
#define x0 _x0_
#define y1 _y1_
const int N = 5e5 + 5;
using namespace std;
void gmax(int &x,int y) {
	x = max(x,y);
	return ;
}
int n,a[N]; 
int s[N];
int m;
void solve(){
	cin >> n >> m;
	For(i,1,n) cin >> a[i];
	sort(a+1,a+1+n);
	For(i,1,n) s[i] = s[i - 1] + a[i];
	int ans = 0;
	For(i,1,n) {
		int l = 1,r = i - 1;
		while(l + 3 <= r) {
			int mid = (l + r )>> 1;
			if(a[i] * (i - mid) - (s[i - 1] - s[mid - 1]) <= m) r = mid;
			else l = mid;
		}For(mid,l,r) {
			if(a[i] * (i - mid) - (s[i - 1] - s[mid - 1]) <= m) gmax(ans,i - mid + 1);
		}
	}cout << ans << endl;
}signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int T = 1;
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
//	cin >> T;
	while(T--) solve();
	return 0;
}
