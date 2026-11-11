#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+10;
ll n,m,a[N],sum,ans=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(ll i=n,j=n;i>1;i--){
		if(j>i){ sum=0; j=i; }
		while(j>1&&sum+a[i]-a[j-1]<=m){
			sum+=a[i]-a[j-1]; j--;
			ans=max(ans,i-j+1);
		}
		sum-=(i-j)*(a[i]-a[i-1]);
	}
	cout<<ans;
	return 0;
} 
