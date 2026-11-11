//观山湖中学 李朋钊 GZ-S00201
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e5 + 10;
const int M = 2e5 + 10;
const int inf = 0x3f3f3f3f;
const ll Inf = 0x3f3f3f3f3f3f3f3f;
template<typename U, typename V> bool cmin(U &x,const V &y){return y<x?x=y,1:0;}
template<typename U, typename V> bool cmax(U &x,const V &y){return y>x?x=y,1:0;}
int n;ll m, a[N], pre[N], ans=-1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1, a+1+n);
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
	}
	if(n==1) return cout<<0, 0;
	if(n==2) return cout<<2*(a[2]-a[1]<=m), 0;
	for(int i=3;i<=n;i++){
		ll l=0, r=i-1;
		while(l+1!=r){
			int mid=l+r>>1;
			ll s=i-mid;
			if((ll)a[i]*s-(ll)(pre[i-1]-pre[mid-1])<=m){
				cmax(ans, i-mid+1);
				r=mid;
			}else l=mid;
		}
	}
	cout<<ans<<'\n';
	return 0;
}
