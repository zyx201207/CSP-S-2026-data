//这吧唧啥题啊 做的我心生爱慕了 直接暴力？？
//坏事 第三个样例就炸了 
//不对 我有思路了 --- 17:14 !!!
//完了TVT 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m;
const ll N=5*1e5+5000;
ll a[N];
ll f=0;
ll c=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(ll i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	ll x=n/2+n%2;
	if(n==2)x=n/2+1;
	for(ll i=x;i<=n;i++){
		if(a[i]==a[x])f++;//重复 
	}
	for(ll i=1;i<=x;i++){
		m-=(a[x]-a[i]);
		if(m<0){
			m+=(a[x]-a[i]);//防止中间就退出 
			continue;
		}
		if(m>=0)c++; 
		//cout<<m<<" "<<c<<"\n";
	}
	if(c!=0)cout<<c+f-1;
	else cout<<1;
	return 0;
}
/*
5 5
1 2 4 8 9 ---3

5 8
-3 -1 2 2 7 ---4

4 1
2 4 6 8 ---1

6 4
2 4 6 8 10 12 --- 2

4 4
2 4 6 8 --- 2

5 6
1 5 3 2 7 --- 3

2 1
1 2 --- 2
Oct31==Dec25?
*/
