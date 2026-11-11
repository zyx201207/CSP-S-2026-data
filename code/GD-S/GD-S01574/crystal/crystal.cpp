#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define pii pair<int,int>
#define fi first
#define se second
#define eb emplace_back
#define ep emplace
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define mems(arr,x) memset(arr,x,sizeof(arr))
#define memc(arr1,arr2) memcpy(arr1,arr2,sizeof(arr2))
using namespace std;
bool mem1;
namespace OIMATT{
	const int maxn=5e5+10;
	int n;ll m;
	ll a[maxn],b[maxn];
	bool check(int x){
		for(int i=x;i<=n;i++){
			ll w=a[i]*x-(b[i]-b[i-x]);
			if(w<=m)	return true;
		}
		return false;
	}
	void solve(int _c){
		cin>>n>>m;
		for(int i=1;i<=n;i++)	cin>>a[i];
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++)	b[i]=b[i-1]+a[i];
		int l=0,r=n,ans=0;
		while(l<=r){
			int mid=(l+r)>>1;
			if(check(mid))	ans=mid,l=mid+1;
			else	r=mid-1;
		}
		cout<<ans<<'\n';
	}
}
bool mem2;
int main(){
	freopen("crystal.in","r",stdin);freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	debug("%.2fMB\n",abs(&mem1-&mem2)/1024./1024);
	int T=1;for(int i=1;i<=T;i++)OIMATT::solve(i);
	debug("%.0fms\n",double(clock())/CLOCKS_PER_SEC*1000);
}