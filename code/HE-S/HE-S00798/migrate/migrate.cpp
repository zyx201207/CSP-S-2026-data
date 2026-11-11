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
#define N 100005
#define mod 998244353
int n,d,x[N],b[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int c,t;cin >> c >> t;while(t--){
		cin >> n >> d;
		rep(i,1,n){
			cin >> x[i];
		}
		int dif = x[n] - x[n-1];
		if(dif > d){cout << 0 << endl;continue;}
		if(d/dif > 2){cout << 0 << endl;continue;}
		cout << n -3 << endl;
	}
	ciallo
}


