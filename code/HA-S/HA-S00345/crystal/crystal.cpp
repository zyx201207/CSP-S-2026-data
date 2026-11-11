#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define maxn 600005
#define inf 0x7f7f7f7f7f7f7f7f

int n;
ll m;
ll a[maxn],sum[maxn];
ll ans=1;


int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	
	sum[0]=0;
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	
	for(ll i=1,j=1;i<=n;i++){
		if((i-j)*a[i]-(sum[i]-sum[j-1])<=m){
			if(ans<(i-j+1)){
				ans=i-j+1;
			}
		}
		else{
			for(;j<=i;j++){
				if((i-j)*a[i]-(sum[i-1]-sum[j-1])<=m){
					break;
				}
			}
		}
	}
	cout<<ans;
	
	return 0;
}
