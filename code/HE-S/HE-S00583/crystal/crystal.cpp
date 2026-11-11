#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e5+5;
ll n,m;
ll a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ll cnt=0,ans=1;
	for(ll i=2,j=1;i<=n;i++){
		cnt+=(i-j)*(a[i]-a[i-1]);
		while(cnt>m&&j<i){
			cnt-=a[i]-a[j];
			j++;
		}
//		cout<<i-j+1<<endl;
		ans=max(i-j+1,ans);
	}
	cout<<ans;
	return 0;
}
