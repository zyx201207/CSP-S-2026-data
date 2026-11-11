#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF=5*1e5+25;
long long n,m,ans=LONG_LONG_MIN;
long long a[INF],cz[INF],c[INF];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","W",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	long long l=1,r=n,mid=(l+r)/2;
	bool pd=true,pd1=true,d=0;
	a[0]=0,a[n+1]=0;
	int shu1,shu2;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=a[2]-a[1]){
			pd=false;
			break;
		}
	}
	if(pd==true){
		m/=(a[2]-a[1]);
		int sum=0;
		int k=1;
		for(k=1;;k++){
			sum+=k;
			if(sum+(k+1)>m){
				break;
			}
		}
		cout<<k+1;
		return 0;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		if(i==1){
			continue;
		}
		for(int j=i-1;j>=1;j--){
			long long sum=0;
			c[j-1]=0;
			c[j]=c[j+1]+(a[i]-a[j]);
			if(c[j]<=m){
				ans=max(ans,i-j+1);
			}
		}
	}
	cout<<ans;
	return 0;
}
