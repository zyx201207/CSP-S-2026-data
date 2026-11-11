//跪求100pts
//I love CCF!
/*45分暴力：
二维差分(前缀和？)
二分答案次数
ans=max(ans,cnt);

性质A:
二分(n+1)n/2 
奇数*2,偶数 eg:3?+4?

性质B:
算出公差
二分(首项+末项)*项数/2 
奇数*2,偶数 eg:3?+4?

我该在哪里停留，我问我自己
唉 
代码实现能力还爱是太差了
此生无悔入OI 
luogu Uid:1998196 
*/
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#define ll long long
using namespace std;
const int MAXN=500010,mod=1e9+7;
ll n,m,a[MAXN],b[MAXN],c[MAXN],ans=0;

ll csum(ll x){
	return x*(x+1)/2;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	if(n>5000){
		for(int i=1;i<=n;i++) cin>>a[i];
		if(a[1]==1 && a[2]==2 && a[3]==3){//性质A 
			if(n%2==1){//合到中间数
				ll l=0,r=0x7f7f7f7f,mid;
				while(l+1<=r){
					mid=(l+r)/2;
					if(csum(mid)*2>m){
						r=mid;
					}else{
						l=mid;
					}
				}
				cout<<l*2+1;
			}else{//两个中间数
				ll l=0,r=0x7f7f7f7f,mid;
				while(l+1<r){
					mid=(l+r)/2;
					if(csum(mid)+csum(mid+1)>m){
						r=mid;
					}else{
						l=mid;
					}
				}
				cout<<l*2+2;
			}
		}else{//性质B
			if(n%2==1){//合到中间数
				ll l=0,r=0x7f7f7f7f,mid,cha=a[2]-a[1];
				while(l+1<=r){
					mid=(l+r)/2;
					if(csum(mid)*2>m){
						r=mid;
					}else{
						l=mid;
					}
				}
				cout<<l*2+1;
			}else{//两个中间数
				ll l=0,r=0x7f7f7f7f,mid;
				while(l+1<r){
					mid=(l+r)/2;
					if(csum(mid)+csum(mid+1)>m){
						r=mid;
					}else{
						l=mid;
					}
				}
				cout<<l*2+2;
			}
		}
		return 0;
	}
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	ll cnt;
	for(int i=1;i<=n;i++){//枚举中间数
		for(int j=1;j<=n;j++) b[j]=abs(a[i]-a[j]);
		sort(b+1,b+n+1);
		for(int j=1;j<=n;j++){
			c[j]=c[j-1]+b[j];
			//cout<<c[j]<<" ";
		}
		//ll pos=lower_bound(c+1,c+n+1,m)-c;
		//ll pos=upper_bound(c+1,c+n+1,m)-c;
		ll l=1,r=n+1,mid;
		while(l+1<r){
			mid=(l+r)/2;
			if(c[mid]<=m){
				l=mid;
			}else{
				r=mid;
			}
		}
		//ans=max(l,ans);
		if(l>ans){
			ans=l;
			cnt=i;
		}
	}
	cout<<ans;//<<" "<<cnt;
	return 0;
}
