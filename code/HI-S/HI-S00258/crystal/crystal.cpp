#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int N = 5e5+5;

int a[N],n;

ll m,Pre[N];

inline bool check(int i,int j){
	ll w = (i-j+1) * a[i] - (Pre[i] - Pre[j-1]);
	
	return w <= m;
}
inline int Bound(int l,int r,int i){
	if(l == r) return l;
	
	int mid = l + r >> 1;
	
	if(check(i,mid)) return Bound(l,mid,i);
	return Bound(mid+1,r,i);
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	cin >> n >> m;
	for(int i = 1;i<=n;++i) cin >> a[i];
	
	sort(a+1,a+n+1);
	
	for(int i = 1;i<=n;++i) Pre[i] = Pre[i-1] + a[i];
	
	int ans = 1;
	for(int i = 2;i<=n;++i){
		/*int siz = 0;//ai
		
		ll w = 0;
		
		for(int j = i;j;--j){
			if(w + a[i]-a[j] <= m){
				w += a[i]-a[j];
				++siz;
			}else{
				cout << j+1 << ' ';
				break;
			}
		}*/
		
		
		int j = Bound(1,i,i);
		
		//cout << j << '\n';
		
		ans = max(ans,i-j+1);
	} 
	
	cout << ans;
	return 0;
}

