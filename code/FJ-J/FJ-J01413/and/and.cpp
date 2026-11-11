#include<bits/stdc++.h>
#define ll long long
using namespace std;

	ll n,m;
	ll ans1,ans=0;
	ll a[400010];
	ll MAX=pow(2,31)-1;
ll f(ll x,ll y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1,f);
	for(ll i=1;i+m-1<=n;i++){
		ans1=MAX;
		for(ll j=1;j<=m;j++)ans1&=a[i+j-1];
		ans=max(ans,ans1);
	}
	cout<<ans<<"\n";
	return 0;
}
//T3
//少年不知哈希好，爱上摸鱼，爱上摸鱼，为了开心强摸鱼。
//而今识尽MLE，欲说还休，欲说还休，却道“天凉好个秋”。
//想到T4怎么做了，但不会map，苦呀西！ 
//I love ccf! 
//ccf这么好，一定会多给我分的吧，谢谢！ 
