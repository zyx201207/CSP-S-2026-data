#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m,ans;
long long a[N],sum[N],c[N],costp;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		//cout<<c[i]<<" ";
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		c[i]=a[i]-a[i-1];
		sum[i]=sum[i-1]+c[i];
	}
	long long l=1,ci=0;
	for(int i=2;i<=n;i++){
		ci++;
		costp+=ci*c[i];
		while(l<i&&costp>m){
			//cout<<l<<" "<<i<<" "<<cost<<endl;
			l++,ci--;
			costp-=sum[i]-sum[l-1];
		}
		//cout<<l<<" "<<i<<" "<<cost<<endl;
		ans=max(ans,i-l+1);
	}
	cout<<ans; 
	return 0;
} 
