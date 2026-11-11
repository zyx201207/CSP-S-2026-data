#include<iostream>
#include<algorithm>
//#include<unordered_map>
#define ll long long
#define F(i,x,y) for(int i=x;i<=y;i++)
#define F2(i,x,y) for(int i=x;i>=y;i--)
#define f(x,y) for(auto x:y)
#define lt(x) x&-x
#define d2(l,r) (l+r>>1)
#define ls(i) i<<1
#define rs(i) i<<1|1
using namespace std;
const int N=5e5+15;
int n;
ll m,a[N],c[N],s[N];
//unordered_map<ll,int> mp;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	F(i,1,n) cin>>a[i];
	sort(a+1,a+n+1);
	F(i,1,n-1) c[i]=a[i+1]-a[i];
	F2(i,n-1,1){
		c[i]+=c[i+1];
		s[i]=s[i+1]+c[i];
//		cout<<i<<' '<<c[i]<<' '<<s[i]<<endl;
	}
	ll ans=-1;
	F(i,1,n-1){
		ll x=m+s[i+1];
		ll lb=1,ub=i,p;
		while(lb<=ub){
			int mid=d2(lb,ub);
			if(s[mid]-(i-mid+1)*c[i+1]<=x){
				ub=mid-1;
				p=mid;
			}else lb=mid+1;
		}
		if(s[p]-(i-p+1)*c[i+1]<=x) ans=max(ans,i-p+2LL);
//		cout<<p<<' '<<s[p]-(i-p+1)*c[i+1]<<' '<<x<<endl;
	}
	cout<<ans<<endl;
	return 0;
} 
