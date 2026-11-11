#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long nn,n,m,aa[N],a[N],sum,ans,b[N],c[N],d[N],maxl,pd,pd1,xb;
int main(){
	freopen("crystal.in","r",stdin);	
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&nn,&m);
	for(int i=1;i<=nn;i++){
		scanf("%lld",&aa[i]);
	}sort(aa+1,aa+1+nn);
	for(int i=1;i<=nn;i++)if(aa[i]!=i)pd=1;
	for(int i=3;i<=nn;i++)if(aa[i]-aa[i-1]!=aa[i-1]-aa[i-2])pd1=1;
	for(int i=1;i<=nn;i++){
		if(aa[i]==aa[i+1])sum++;
		else n++,a[n]=aa[i],c[n]=sum+1,sum=0;
	}
	if(pd==0||pd1==0){
		sum=a[2]-a[1];ans=1;d[1]=0;
		for(int i=2;i<=n;i++){
			d[i]=(i-1)*sum+d[i-1];
			if(d[i]>m){
				cout<<i-1;
				return 0;
			}
		}
	}
	for(int i=2;i<=n;i++){ 
		sum=m;ans=c[i];
		for(int j=i-1;j>=1;j--){
			if(sum>=(a[i]-a[j])*c[j])sum-=(a[i]-a[j])*c[j],ans+=c[j];
			else break;
		}
		if(ans>maxl)maxl=ans;
	}
	printf("%lld",maxl);
	return 0;
} 
