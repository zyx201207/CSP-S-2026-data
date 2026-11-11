#include<bits/stdc++.h>
using namespace std;
long long a[600000],n,m,f[600000],sum[600000],pw[1000],ans=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	//cout<<n<<" "<<m<<endl;
	pw[0]=1;
	for(int i=1;i<=31;i++){pw[i]=pw[i-1]*2;}
	for(long long i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(long long i=1;i<=n;i++){sum[i]=sum[i-1]+a[i];}
	for(long long i=2;i<=n;i++){
		f[i]=(a[i]-a[i-1])*(i-1)+f[i-1];
		long long cnt=i;
		for(long long j=30;j>=0;j--){
			if(cnt-pw[j]<=0) continue;
			if(f[i]-(a[i]*(cnt-pw[j]-1)-sum[cnt-pw[j]-1])>m) continue;
			cnt-=pw[j];
			//mm-=f[i]-(a[i]*(cnt-pw[j]-1)-sum[cnt-pw[j]-1]);
		}
		//cout<<cnt<<' ';
		ans=max(ans,i-cnt+1);
	}
	cout<<ans;
	return 0;
}
