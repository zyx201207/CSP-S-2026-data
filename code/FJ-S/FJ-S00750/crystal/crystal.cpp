#include<bits/stdc++.h>
using namespace std;
int n,head,cnt,maxn;
long long m,a[500002],d[500002],sum1;
int main(){
	cnt=maxn=1;sum1=0;head=1;
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++){
		d[i]=a[i+1]-a[i];
	}
	for(int i=1;i<n;i++){
		if(sum1+d[i]*(i-head+1)<=m){
			sum1=sum1+d[i]*(i-head+1);cnt++;
		}
		else{
			while(sum1+d[i]*(i-head+1)>m&&head<=i){
				sum1=sum1-(a[i]-a[head]);head++;cnt--;
			}
			if(head>i)continue;
			if(sum1+d[i]*(i-head+1)<=m){
			sum1=sum1+d[i]*(i-head+1);cnt++;
			}
		}
		if(cnt>maxn)maxn=cnt;
	}
	printf("%d",maxn);
	return 0;
}
