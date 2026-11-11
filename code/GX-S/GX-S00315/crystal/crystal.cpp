#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,ans=-1e9;
ll a[500005],d[500005];
ll N=1e18;

ll sum=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(ll i=a[n];i>=a[1];i--){
		sum=0;
		for(int p=1;p<=n;p++){
			d[p]=0;
		}
		for(int j=1;j<=n;j++){
			if(a[j]>i){
				d[j]=N;
			}else{
				d[j]=i-a[j];
			}
		
		}
		sort(d+1,d+1+n);
		
		ll L=m;
		for(int k=1;k<=n;k++){
			if(L>=d[k]){
				L-=d[k];
				sum++;
			}
		}
		
		ans=max(ans,sum);
	}
	cout<<ans;
	return 0;
	
}
