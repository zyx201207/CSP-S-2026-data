//数组越界
//mle 

#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
typedef long long ll;
ll n,m;
ll a[N];
ll d[N];
ll ans=0;
bool f;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		d[i]=a[i]-a[i-1];
		if(d[i]!=d[i-1])f=1;
	}
	if(f){
		for(int i=1;i<=n;i++){
			ll k=1,cnt=0;
			for(int j=i;j<=n;j++,k++){
				cnt+=(k*d[j]);
				if(cnt>m){
					ans=max(ans,k);
					break;
				}
			}
		}
	}
	else{
		ll cnt=0;
		for(int i=1;i<=n;i++){
			cnt+=d[i]*i;
			if(cnt>m){
				ans=i;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7

5 7
1 3 5 7 9
*/
