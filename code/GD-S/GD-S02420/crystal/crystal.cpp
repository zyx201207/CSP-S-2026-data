#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=5e5+10;
//注意负数
//选定一个基准数，且该数应在条件下尽可能大 
//二分,贪心 
ll n,m,a[maxn];
bool pdA=true;
void solveA(){//二分，特殊性质A 
	ll l=1,r=n;
	while(l<=r){
		ll mid=l+(r-l)/2;
		if((mid*(mid+1))/2<=m){
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	cout<<r+1;
}
ll maxsum=0;
bool check(ll mid){
	ll sum=0,cnt=1;
	for(int i=n;i>=1;i--){
		if(a[i]<mid){
			sum+=mid-a[i];
			if(sum>m){
				return false;
			}
			cnt++;//记录当前mid最多能合成几个大水晶 
			maxsum=max(maxsum,cnt);
		}
	}
	return true;
}
void solve1(){//二分,尝试正解 
	ll l=1,r=n;
	while(l<=r){//找基准值 
		ll mid=l+(r-l)/2;
		if(check(mid)){
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	ll ans=upper_bound(a+1,a+n+1,r)-a-1;//注意可能有相同数字
	cout<<max(maxsum,ans);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i){
			pdA=false;
		}
	}
	sort(a+1,a+n+1);
	ll maxs=0;
	for(int i=1;i<=n;i++){
		maxs+=a[n]-a[i];
	}
	if(maxs<=m){//m值足够大，可以让所有数相同 
		cout<<n;
	}
	else if(pdA){
		solveA();
	}
	else{
		solve1();
	}
	return 0;
}
