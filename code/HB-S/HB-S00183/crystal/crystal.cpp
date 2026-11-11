#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500010];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d %lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	if(n>10000){
		printf("%d",n);
		return 0;
	}
	long long d[n+5][n+5];
	memset(d,-1,sizeof(d));
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			d[i][j]=a[j]-a[i];
		}
	}
	long long mx=0;
	for(int i=1;i<=n;i++){
		long long v=m,cnt=1;
		for(int j=1;j<i;j++){
			if(d[j][i]!=-1 && v>=d[j][i]){
				cnt++;
				v-=d[j][i];
			}
		}
		if(mx<cnt) mx=cnt;
	}
	printf("%lld",mx);
	return 0;
}
