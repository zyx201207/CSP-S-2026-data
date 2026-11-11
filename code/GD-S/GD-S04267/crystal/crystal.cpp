#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=500050;
ll a[N];
ll qz1[N],qz2[N]; 
//qz1记录普通差分前缀和，qz2记录带权差分前缀和 
//qz[i]表示1到i的差分前缀和 
ll n,m;
ll ans;
bool check(ll lt,ll rt){//计算a[lt]到a[rt]的差分带权和 
	ll sum=qz2[rt]-qz2[lt]-(lt-1)*(qz1[rt]-qz1[lt]);
	//cout<<lt<<","<<rt<<","<<sum<<"\n";
	return sum<=m;
}
bool cmp(ll a,ll b){
	return a<b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n,cmp);
	for(ll i=2;i<=n;i++){
		ll sub=a[i]-a[i-1];
		qz1[i]=qz1[i-1]+sub;
		qz2[i]=qz2[i-1]+sub*(i-1);
	}
	for(ll i=1;i<=n;i++){//枚举目标水晶 
		ll l=1,r=i;
		ll t=i;//一开始最远能到达i 
		while(l<=r){
			ll mid=(l+r)>>1;//尝试的最远水晶位置 
			if(check(mid,i)){
				t=mid;
				r=mid-1;
			}
			else l=mid+1;
		}
		//cout<<t<<"\n";
		ans=max(ans,i-t+1);
	}
	cout<<ans;
	return 0;
}
