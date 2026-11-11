#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int ans=1;
	int nans=0;
	int sum=0;
	int whe=n;
	for(int i=n;i>=1;i--){
		if(whe<=1){
			break;
		}
		if(sum+a[whe]-a[i]>m){
			ans=max(ans,nans);
			whe--;
			nans--;
			sum-=(a[whe+1]-a[whe])*nans;
		}
	    sum+=(a[whe]-a[i]);
	    nans++;
//	    cout<<nans<<' '<<sum<<' '<<whe<<endl;
	}
	ans=max(ans,nans);
	cout<<ans<<endl;
	return 0;
}
