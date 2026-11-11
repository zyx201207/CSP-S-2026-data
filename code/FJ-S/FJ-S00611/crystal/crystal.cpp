#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = LONG_LONG_MAX;
const ll N = 5e5+10;
ll n,m;
ll a[N],p[N];
ll ret = -INF;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++){
		p[i] = p[i-1]+a[i];
	}
	for(ll i=1;i<=n;i++){
		ll l=1,r=i;//我们二分可以选择的范围
		ll ans = i; 
		while(l<=r){
			ll mid = (l+r)/2;
			//代价为tmp 
			ll tmp = a[i]*(i-mid+1)-(p[i]-p[mid-1]); 
			//如果说可以做的到 
			if(tmp<=m){
				r = mid-1;//我们只需要考虑mid-1内的东西 
				ans = mid;
			}
			else{
				l = mid+1; 
			} 
		}
	//	cout<<i<<" "<<ans<<endl;
		ret = max(ret,i-ans+1);
	}
	cout<<ret;
	return 0;
}
/*
首先 不难注意到需要最后产生答案 及合成水晶中每一个位置的值都应该是 a[i]中的一个数
那么我们先排序 
然后枚举这个数
然后我们不难发现
如果说我们选了a[i]
那么贪心 显然有
a[i]-a[i-1]
a[i]-a[i-2]
这些东西为产生的代价
我们还发现选择的数量是具有单调性的
所以我们二分这个选择的数k
然后显然可以用前缀和来作出这个东西的计算
所以就昨晚了
显然可以支持开long long

5 5
1 2 4 8 9 

5 8
-3 -1 2 2 7
*/
