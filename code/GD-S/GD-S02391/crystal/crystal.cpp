#include<bits/stdc++.h>
using namespace std;
const int N=5e6+10;
int n,ans=1;
long long m;
bool cmp(long long a,long long b){return a>b;}
long long a[N],b[N];
int main(){
    freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+1+n,cmp);
	for(int i=2;i<=n;i++) b[i]=a[i-1]-a[i];
	long long qzh=0,sum=0;int j=2;
	for(int i=1;i<n;i++) {
		 while(sum+qzh+b[j]<=m&&j<=n){
		 	sum=sum+qzh+b[j];
		 	qzh+=b[j];
			j++;
		}
		ans=max(ans,j-i);
		sum-=(j-i)*b[i+1];
		qzh-=b[i+1];
		if(n-i+1<=ans) break;
	} 
	printf("%d\n",ans); 
	return 0;
} 
