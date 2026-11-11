#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=2000005;

int c;

ll n,d;
ll x[MAXN];

int bt[MAXN];//belong to (block)
int ed[MAXN];

void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;++i) cin>>x[i];
	if(n<=3){
		cout<<"0\n";
		return ;
	}
	if(c==11||c==12){
		ll k=x[2]-x[1];
//		cerr<<n<<' '<<d<<' '<<k<<'\n';
		d=d/k*k;
		if(d/k>=2&&n-(d/k*2-1)>0) cout<<n-(d/k*2-1)<<'\n';
		else cout<<"0\n";
		return ;
	}
	else if(c==13||c==14){
		int p;
		for(int i=1;i<=n;++i){
			if(x[i]-x[1]<=d&&x[n]-x[i]<=d){
				p=i;break;
			}
		}
		if(p==1||p==n){
			cout<<"0\n";
			return ;
		}
		int pl,p2l;
		for(pl=p;pl<=n&&x[pl]-x[p-1]<=d;++pl);pl--;
		for(p2l=p;p2l<=n&&x[p2l]-x[p-2]<=d;++p2l);p2l--;
//		cerr<<p<<'\n'<<pl<<' '<<p2l<<';';
		ll ans=0;ans+=((ll)p-2)*((ll)pl-p2l);
		for(pl=p;pl>=1&&x[p+1]-x[pl]<=d;--pl);pl++;
		for(p2l=p;p2l>=1&&x[p+2]-x[p2l]<=d;--p2l);p2l++;
//		cerr<<pl<<' '<<p2l<<'\n';
		ans+=((ll)n-(p+1))*((ll)p2l-pl);
		cout<<ans<<'\n';
		return ;
	}
	cout<<"0\n";
}
/*
13 4
4 5
-1 0 3 5
5 5
-2 -1 0 1 3
5 5
-3 -1 0 1 3
13 7
-7 -6 -5 -4 -3 -1 0 1 2 3 4 5 6
*/
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0),cout.tie(0);
	int T;cin>>c>>T;
	while(T--) solve();
	return 0;
} 
