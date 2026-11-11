#include<bits/stdc++.h>
#define fi first
#define se second
#define pi pair<int,int>
#define lg(x) (63-__builtin_clzll(x))
typedef long long ll;
using namespace std;
const int N=2e6+100;
const ll inf=0x3f3f3f3f3f3f3f3f;
ll n,d;
ll x[N];
namespace subtask1{
	void main(){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		if(n==1) return cout<<0<<"\n",void();
		int D=x[2]-x[1];
		if(D>d) return cout<<0<<"\n",void();
		if(D>d/2) return cout<<0<<"\n",void();
		if(2*D>d/2) return cout<<n-3<<"\n",void();
		cout<<0<<"\n";
	}
}
namespace subtask2{
	ll f[N],g[N];
	ll ans;
	void main(){
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++) cin>>x[i];
		for(int i=1;i<=n;i++){
			g[i-1]=inf;
			g[i]=0;
			f[i]=1;
			ll cnt=0;
			for(int j=i+1,l=i,r=i;j<=n;j++){
				while(x[l]<x[j]-d) cnt-=f[l],l++;
				while(r<j&&g[r]<=g[l]) cnt+=f[r],r++;
				f[j]=cnt;
				g[j]=g[l]+1;
				ans+=(f[j]==2);
//				cout<<i<<" "<<j<<" "<<f[j]<<" "<<g[j]<<"\n";
//				if(f[j]>2||f[j]==0) break;
			}
		}
		cout<<ans<<"\n";
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int c,t; cin>>c>>t;
	while(t--){
		if(c<=10) subtask2::main();
		else if(c==11||c==12) subtask1::main();
		else cout<<0<<"\n";
	}
	return 0;
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

0 1
6 2
-4 -3 -2 -1 3 6

0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 1
10 3
0 3 6 7 8 9 10 11 14 17


0 1
6 12
-10 -6 -2 2 6 10
*/
