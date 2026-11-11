#include<bits/stdc++.h>
using namespace std;
long long m,n,a[500005],fc[500005]={},tot[500005]={};
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(long long i=2;i<=n;i++){
		fc[i]=a[i]-a[i-1];
		tot[i]=tot[i-1]+fc[i]*(i-1);
		//cout<<tot[i]<<endl;
	}
	
	long long maxlen=1;
	for(long long i=1;i<n;i++){
		for(long long j=i+maxlen;j<=n;j++){
			if(tot[j]-tot[i]<=m&&j-i+1>maxlen){
				maxlen=j-i+1;
				//j=i+maxlen;
			}
			//printf("i=%lld,j=%lld,maxlen=%lld\n",i,j,maxlen);
		}
	}
	cout<<maxlen;
	return 0;
}

