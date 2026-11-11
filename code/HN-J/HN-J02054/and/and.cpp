#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[200005];
bool cmp(ll a,ll b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	ll ans=-1;
	for(int i=1;i<=n;i++){
		if(a[i]<=ans){
			break;
		}
		ll sum=a[i];
		for(int j=i+1;j<=i+m-1;j++){
			sum=sum&a[j];
			if(sum<=ans){
				break;
			}
		} 
		ans=max(sum,ans);
	}
	cout<<ans;
	return 0;
} 
