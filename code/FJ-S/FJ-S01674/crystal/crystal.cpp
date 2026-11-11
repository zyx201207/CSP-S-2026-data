#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll a[500010];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m;cin>>n>>m;
	for(ll i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	ll i=0,j=0,cnt=0,ans=0;
	while(i<=j&&i<=n&&j<=n){
		while(cnt<=m&&j<=n){
			j++;
			cnt+=(a[j]-a[j-1])*(j-i-1);
			if(cnt<=m&&cnt>=0)ans=max(ans,j-i);
//			cout<<i<<" "<<j<<" "<<cnt<<" "<<ans<<endl;
		}
		while(cnt>m&&i<=n){
			i++;
			cnt-=(a[j]-a[i]);
//			cout<<i<<" "<<j<<" "<<cnt<<" "<<ans<<endl;
		}
	}
	cout<<ans;
	return 0;
}

/*
5 5
1 2 4 8 9

3
*/
/*
5 4
1 2 4 8 9

3
*/
/*
5 8
-3 -1 2 2 7

4
*/
