#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int ans=-1;
	for(ll i=1;i<=n;i++){
		int mm=m;
		int sum=1;
		for(ll j=i-1;j>=1;j--){
			int b=a[i]-a[j];
			if(mm>=b){
				sum++;
				mm-=b;
			}
		}
		ans=max(ans,sum);
	}
	cout<<ans;
}


