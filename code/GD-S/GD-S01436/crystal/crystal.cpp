#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long d[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		d[i]=a[i]-a[i-1];
	}
	d[1]=0;
	int ans=0;
	long long cnt=0,sum=0,k=0;
	for(int i=2,j=1;i<=n;i++){
		j=max(j,i-1);
		while(j<n && sum+(k+1)*(d[j+1])<=m){
			sum+=(++k)*d[++j];
//			cout<<i<<' '<<j<<' '<<sum<<'\n';
			cnt+=d[j];
		}
		ans=max(ans,j-i+2);
		sum-=cnt;
		cnt-=d[i];
		k--;
	}
	cout<<ans<<'\n';
}
