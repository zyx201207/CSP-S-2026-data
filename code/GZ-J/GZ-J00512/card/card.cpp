//GZ-J00512 易煊培 兴义市弘毅中学 
#include<bits/stdc++.h>
using namespace std;

long long n,m,c=0,mn[500010]={0},a[500050]={0},cnt[500010]={0};

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i=0;i<n;i++) {
		cin>>a[i];
	}
	for(long long i=0;i<n;i++){
		c=i;
		long long j=0,xh=n;
		for(;j<xh;j++){
			for(long long k=0;k<j;k++) if(mn[k]==a[c]) {
				xh-=(j-k);
				j=k;
				break;
			}
			mn[j]=a[c];
			c++;
		}
		for(long long k=0;k<xh;k++) {
			cnt[mn[k]-1]+=1;
		}
	}
	for(long long j=0;j<m;j++) cout<<cnt[j]<<' ';
	return 0;
}  
