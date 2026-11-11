#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define bep(i,a,b) for(int i = a; i >= b; i--)
const int N = 5e5+10;
using namespace std;
int a[N],mca[N],pre[N];
int check(int l, int r){
	return mca[r]*(r-l)-(pre[r-1]-pre[l-1]);
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n, m;
	cin >> n>>m;
	rep(i,1,n) cin >> a[i]; 
	sort(a+1,a+n+1);
	rep(i,2,n)mca[i]=a[i]-a[i-1]+mca[i-1];
	rep(i,2,n)pre[i]=pre[i-1]+mca[i];
	int mx = 1;
	rep(i,2,n){
		int l = 1, r = i-1,ans = -1;
		while(l <= r){
			int mid = (l+r)/2;
			if(check(mid,i)<=m){
				ans = mid,r = mid-1;
			}else l = mid+1;
		}
		mx = max(mx, i-ans+1);
	}
	cout <<mx;
	return 0;
}
