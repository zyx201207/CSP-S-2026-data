#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long
const int maxn=5e5+5;

ll n,m;
ll a[maxn],q[maxn];

bool check(ll x){
	ll le=1,ri=x,t=m;
	while(ri<=n){
		ll sum=q[ri]-q[le-1];
		if(a[ri]==0) a[ri]=1; //shiÈË°¡ 
		//cout<<x<<" "<<(t+sum)/a[ri]<<endl;
		if(x<=(t+sum)/a[ri]) return 1;
		ri++;le++;
	}
	return 0;
}

int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	if(n==1){ //ÌØÅÐ 
		int p;cin>>p;
		cout<<p+m;return 0;
	}
	
	for(int i=1;i<=n;i++) cin>>a[i];
	
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) q[i]=q[i-1]+a[i];
	
	ll l=1,r=n,mid;
	while(l<=r){
		mid=(l+r)/2;
		if(check(mid)){
			//cout<<mid<<" 1"<<endl;
			l=mid+1;
		}else{
			//cout<<mid<<" 2"<<endl;
			r=mid-1;
		}
	}
	
	cout<<r;
	
	return 0;
} 
