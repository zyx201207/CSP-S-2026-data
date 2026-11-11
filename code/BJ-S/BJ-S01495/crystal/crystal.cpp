#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define F(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define dF(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)
#define pb push_back
#define fi first
#define se second
#define mkp make_pair
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
#define bll __int128
using namespace std;
void fre(){
	freopen("crystal.in","r",stdin),freopen("crystal.out","w",stdout);
}
bool ST;
template<typename T>inline void chkmax(T&x,const T&y){ x=max(x,y); }
template<typename T>inline void chkmin(T&x,const T&y){ x=min(x,y); }
const int maxn=500005;
ll a[maxn],m,pre[maxn];
int n;
void solve(int cid){
	cin>>n>>m;
	F(i,1,n)cin>>a[i];
	sort(a+1,a+n+1);
	F(i,1,n)pre[i]=pre[i-1]+a[i];
	int ans=1;
	F(i,1,n){
		int l=1,r=i-1,pos=i;
		while(l<=r){
			int mid=(l+r)>>1;
			if(1ll*a[i]*(i-mid+1)-(pre[i]-pre[mid-1])<=m)pos=mid,r=mid-1;
			else l=mid+1;
		}
		chkmax(ans,i-pos+1);
	}
	cout<<ans<<'\n';
}
bool ED;
signed main(){
	fre(),ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int allT=1,testid;
	F(_,1,allT)solve(_);
	cerr<<"time used: "<<((double)clock()/CLOCKS_PER_SEC)<<endl;
	cerr<<"memory used: "<<(abs(&ST-&ED)/1024.0/1024.0)<<"MiB"<<endl;
}
// g++ a.cpp -o a -std=c++14 -O2