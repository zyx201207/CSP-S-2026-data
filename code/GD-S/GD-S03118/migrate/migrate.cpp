#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(x,a,b,c) for(int x=a;b;x+=c)
#define rep2(x,a,b,c) for(int x=a;b;x-=c)
#define fop(x) freopen(x".in","r",stdin); freopen(x".out","w",stdout);
const ll N=1e5+20,INF=INT_MAX/3;
ll n,d,a[N];
/*int check(int mid,int x,int y){// 尝试 mid 次跳跃能否从x跳到y
    int now=a[x];
    rep(i,x,i<=y-1,1) while(a[i+1]>x) now+=d,cnt++;
    return cnt<=mid;
}*/
int to_check(int x,int y) {
	/*int l=0,r=y-x+1,minn=INF;
	while(l<=r){
	    int mid=(l+r)/2;
	    if(check(mid,x,y)) minn=mid,r=mid-1;
	    else l=mid+1;
	}//i-j最少要minn次跳跃*/
	vector<int> v;
	int now=a[x];
	rep(i,x,i<=y-1,1) while(a[i+1]>now) now+=d,v.push_back(i);
//	cout<<v.size()<<' ';
	v.push_back(y);
	int len=v.size();
//	for(auto i:v) cout<<i<<' ';
	rep(i,0,i<=len-2,1) if(v[i+1]!=0&&v[i]!=1&&a[v[i+1]]-a[v[i]-1]<=d) return 1;
	return 0;
}
void solve() {
	ll ans=0;
	scanf("%lld%lld",&n,&d);
	rep(i,1,i<=n,1) scanf("%lld",&a[i]);
	rep(i,1,i<=n-1,1) { // 枚举 i,j  to_check() 可以 return 1 则ans++
		rep(j,i+2,j<=n,1) {
			if(i==j) continue;
//            if(i==1&&j==4) cout<<to_check(1,4)<<'  '<<"114514\n";
			if(to_check(i,j)) {
//				cout<<i<<' '<<j<<"\n";	
				ans++;
			}
		}
	}
	printf("%lld\n",ans);
//	cout<<to_check(1,2);
	return ;
}
int main() {
	fop("migrate"); 
	ll c,t;
	scanf("%lld%lld",&c,&t);
	while(t--) solve();
	return 0;
}
