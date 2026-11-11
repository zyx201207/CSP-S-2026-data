#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+5; 

ll n,m;
ll a[N];
ll maxn=1;//最多水晶球个数 

ll qiu(ll l,ll r,ll num){
	for(int i=l;i<=r;i++){
		num-=a[i];
	}
	return num;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		ll l=i,r=n;
		while(l<=r){
			ll sum=(r-l)+1;//个数
			ll num=a[r]*sum;//合并总值
			ll cha=qiu(l,r,num); 
			if(cha<=m){
				maxn=max(maxn,sum);
			}
			r--;
		}
	}
	cout<<maxn<<endl;
	return 0;
} 
