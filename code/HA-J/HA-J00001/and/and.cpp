#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,ans=-12212;
ll a[2000005];
bool cmp(ll x,ll y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		ll sum=a[i];
		for(int j=1;j<m;j++){
			sum&=a[i+j];
		}
		ans=max(ans,sum);
	}
	cout<<ans;
	return 0;
} 
