#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
ll n,m,k=1;
ll a[N],sum=0,ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	if(n==1){
		cout<<1;
		return 0;
	}
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum=sum+(i-k)*(a[i]-a[i-1]);
		if(sum<=m){
			ans=max(ans,i-k+1);
			continue;
		}
		for(;k<i;k++){
			sum=sum-(a[i]-a[k]);
			if(sum<=m){
				k++;
				ans=max(ans,i-k+1);
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
