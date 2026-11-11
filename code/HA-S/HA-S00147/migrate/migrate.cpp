#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const int N=2e6+5;
int c,t;
int n;
ll a[N],nxt[N];
ll d;
void solve(){
	cin >> n >> d;
	for(int i=1;i<=n;++i){
	cin >> a[i];}
	nxt[n]=n+1;
	ull res=0;
	for(int i=1;i<n;++i){
		if(a[i]+d>a[n])nxt[i]=n;
		else nxt[i]=upper_bound(a+1,a+n+1,a[i]+d)-a-1;
	}
	for(int i=1;i<=n;++i){
		int tim=1,x=i;
		while(x<=n&&tim<=100){
			x=nxt[x];
			if(x>n)break;
			if(nxt[x-2]<nxt[x-1]&&nxt[x-1]>x){
				res++;
			}
			tim++;
		}
	}
	cout << res << '\n';
	return ;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--){
		solve();
	}
	return 0;
}
