#include<bits/stdc++.h>
using namespace std;//¿ªlong long !!!!!!!!!!!!!!!!! 
const long long N=5e5+6;
long long n,m,sum;
long long a[N],b[N];
long long cn445,ans;
bool check(long long t,long long en){
	long long w=a[en]*(en-t+1)-(b[en]-b[t-1]);
//	printf("t:%d st:%d st*t:%d b[st]:%d\n",t,st,st*t,b[st]);
	if(w<=m)return true;
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++)scanf("%lld",&a[i]),sum+=a[i];
	
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++)
	b[i]=b[i-1]+a[i],b[n+1]=b[n];
	for(long long i=1;i<=n;i++){
		long long l=0,r=i;long long mid=(l+r)>>1;
		while(l+1<r){
			mid=(l+r)>>1;
			if(check(mid,i))r=mid;
			else l=mid;
		}
		ans=max(ans,i-l);
		
	}
	
	printf("%lld",ans);
	return 0;
}

/*

0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
