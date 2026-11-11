#include<bits/stdc++.h>
using namespace std;
long long sum[200010],zd,ans=0;
int n,a[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		long long sr; char sr2;
		cin>>sr>>sr2;
		sum[i]=sum[i-1]+sr;
		a[i]=sr2-'a'+1;
	}
	zd=sum[n]/2+1;
//	cout<<n<<' '<<sum[n]<<' '<<zd<<endl;
	
	long long i=1,j=n,jj;
	while(sum[i]<=zd){
//		cout<<i<<' ';
		jj=sum[n]-sum[i];
//		if(jj<=zd) break;
		for( ;sum[j]>jj && sum[j]>=zd;j--){
			if(a[j]!=a[i]) ans+=sum[j]-sum[j-1];
//			cout<<"ans="<<ans<<' '<<sum[j]<<' '<<sum[j-1]<<' '<<sum[j]-sum[j-1]<<endl;
		}
		if(sum[j]<jj && a[j+1]!=a[i]){
			if(a[i+1]==a[j+1]) ans-=jj-sum[j];
//			sum[j]=jj-sum[j];
		}
		i++;
	} 
	
	cout<<ans;
	return 0;
} 
