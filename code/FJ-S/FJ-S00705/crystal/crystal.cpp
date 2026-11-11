#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll n,m,a[N],b[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll i,ma=0;
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>a[i];
		b[i]=b[i-1]+a[i];
	}
	sort(a+1,a+n+1);
	for(i=2;i<=n;i++){
		ll j,sum=0,t=m,s=1;
		for(j=i-1;j>=1;j--){
			if(sum+abs(a[i]-a[j])<=t){
				sum+=abs(a[i]-a[j]);
				s++;
			}
			else break;
		}
		ma=max(ma,s);
	}
	cout<<ma;
	return 0;
}
