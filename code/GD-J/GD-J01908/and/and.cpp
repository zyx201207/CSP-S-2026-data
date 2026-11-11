#include<bits/stdc++.h>
#define LL long long
#define P(i,s,t) for(int i=s;i<=t;++i)
#define S(i,s,t) for(int i=s;i>=t;--i)
using namespace std;
const int N=2e5+5;
int n,m,mm;
LL a[N],k,x=1ll<<30ll;
bool bz[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m;
	P(i,1,n) cin>>a[i],bz[i]=1;
	P(i,0,30){
		mm=0;
		P(i,1,n) if(bz[i]) if(a[i]&x) ++mm;
		if(mm>=m){
			k|=x;
			P(i,1,n) if(bz[i]) if(!(a[i]&x)) bz[i]=0;
		}
		x>>=1;
	}
	cout<<k;
	return 0;
}
