#include<bits/stdc++.h>
using namespace std;
#define CO const
#define CC constexpr
#define RE return
#define VE vector
#define PB push_back
#define TET template<class T>
using ll=long long;
using Ci=CO int;using Cl=CO ll;
#define FOR(i,l,r) for(int i=(l);i<=(r);++i)
#define FER(i,r,l) for(int i=(r);i>=(l);--i)
TET CC void Max(T&x,T y){x=max(x,y);}
CC int N=5e5+5;
int n;ll m;
ll a[N],b[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	FOR(i,1,n)cin>>a[i];
	sort(a+1,a+1+n);
	FOR(i,1,n)b[i]=b[i-1]+a[i];
	int la=1,an=1;
	FOR(i,1,n){
		while(a[i]*(i-la+1)-(b[i]-b[la-1])>m)++la;
		Max(an,i-la+1);
	}
	cout<<an;
	RE 0;
}