#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(x,y,z) for(int x=y;x<=z;++x)
#define per(x,y,z) for(int x=y;x>=z;--x)
#define endl '\n'
//#define pb push_back
#define sortv(x) sort(x.begin(),x.end(),greater<int>())
typedef long long ll;
typedef vector<int> vi;
const int N=200005;
int n,a[N],m,ans;
vi mx[N];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	//rep(i,1,n)cin>>a[i];
	rep(i,1,n){
		cin>>a[i];
		per(j,30,0)
			if((a[i]>>j)&1)mx[j].push_back(a[i]);
	}
	per(i,30,0)if((int)mx[i].size()>=m){
		sortv(mx[i]);
		ans=mx[i][0];
		rep(j,1,m-1)ans&=mx[i][j];
		cout<<ans<<endl;
		return 0;
	}
	return 0;
}
