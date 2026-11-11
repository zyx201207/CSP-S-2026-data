#include<bits/stdc++.h>
using namespace std;
long long a[500005],sum[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
		//cout<<sum[i]<<' ';
	}
	//cout<<endl;
	int r=1,ans=0;
	for(int l=1;l<=n;l++){
		while(1){
			if(a[r]*(r-l+1)-(sum[r]-sum[l-1])>m){
				r--;
				break;
			}
			if(r==n)break;
			r++;
			//cout<<l<<' '<<r<<' '<<a[r]*(r-l+1)-(sum[r]-sum[l-1])<<endl;
		}
		
		ans=max(r-l+1,ans);
	}
	cout<<ans;
	return 0;
}
