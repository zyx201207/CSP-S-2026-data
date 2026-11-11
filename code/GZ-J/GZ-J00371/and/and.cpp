//GZ-J00371 代清宸 兴义市弘毅中学 
#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005];
long long maxest=-1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i=0;i<n;i++){
		scanf("%lld",&a[i]);
	}
	for(long long i=1;i<=(1<<n);i++){
		long long cnt=0;
		long long sum=0;
		for(int j=0;j<n;j++){
			if(i&(1<<j)){
				cnt++;
			}
		}
		if(cnt==m){
			for(long long j=0;j<n;j++){
			    if(i&(1<<j)){
				    if(sum==0) sum=a[j];
				    else sum=sum&a[j];
			    }
		    }
		    maxest=max(maxest,sum);
		}
	}
	printf("%lld\n",maxest);
	return 0;
} 
