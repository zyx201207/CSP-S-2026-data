#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<string>
using std::cin;using std::cout;
using std::string;
typedef long long ll;
const int N=5e5+10;
namespace zyh{
	ll a[N];
	int n,ans;
	ll m;
	signed lqr(){
		cin>>n>>m;
		for(int i=1;i<=n;i++) cin>>a[i];
		std::sort(a+1,a+n+1);
		for(int i=1;i<=n;i++) a[i]+=a[i-1];
		for(int i=1;i<=n;i++){
			ll val=a[i]-a[i-1];
			int l=2,r=i,tmp=1;
			while(l<=r){
				int mid=(l+r)/2;
				if(val*ll(mid)-(a[i]-a[i-mid])<=m){
					tmp=mid;
					l=mid+1;
				}else r=mid-1;
			}
			ans=std::max(ans,tmp);
		}
		cout<<ans;
		return 0;
	}
}
void IO_set(string str){
	string s1=str+".in",s2=str+".out";
	freopen(s1.c_str(),"r",stdin);
	freopen(s2.c_str(),"w",stdout);
	std::ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
}
signed main(){
	IO_set("crystal");//easy T1??? 14:47
	return zyh::lqr();
}
