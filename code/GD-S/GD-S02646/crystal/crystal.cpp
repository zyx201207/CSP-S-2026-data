#include<bits/stdc++.h>
using ll=long long;
using namespace std;
const int N=5e5+10;
ll a[N],pre[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll n,m;
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	pre[0]=0;
	sort(a+1,a+1+n);
	for(ll i=1;i<=n;i++){
		pre[i]=pre[i-1]+abs(a[i]-a[1]);
	}
	long long ans=1;
	long long j=1;
	for(ll i=1;i<=n;i++){
		if((i-j+1)*abs(a[i]-a[j])+pre[j-1]-pre[i]+abs((a[j]-a[1])*(i-j+1))<=m){
			ans=max(ans,i-j+1);
		}else{
			while((i-j+1)*abs(a[i]-a[j])+pre[j-1]-pre[i]+abs((a[j]-a[1])*(i-j+1))>m){
				j++;	
			}
		}
	}
	cout<<ans;
	return 0;
}
