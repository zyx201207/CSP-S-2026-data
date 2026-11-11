#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
typedef long long ll;
ll n,m,a[N],cnt=1,c;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	ll l=1,r=2;
	while(l<r&&r<=n){
		c=m;
		for(int i=l;i<=r;i++)
			c=c-(a[r]-a[i]);
		if(c>0){
			r++;
			cnt++;
		}else{
			cout<<cnt;
			return 0;
		}
	}
	return 0;
}
