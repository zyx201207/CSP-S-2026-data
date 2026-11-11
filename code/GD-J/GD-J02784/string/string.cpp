#include<bits/stdc++.h>
using namespace std;
int n;
int a[200007];
char c[200007];
int p1,p2;
long long sum;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d %c",&a[i],&c[i]);
	}
	p1=1;
	p2=n;
	while(p1<p2){
		long long minx=min(a[p1],a[p2]);
		if(c[p1]!=c[p2]){
			sum+=minx;
		}
		a[p1]-=minx;
		a[p2]-=minx;
		if(a[p1]==0) p1++;
		if(a[p2]==0) p2--;
	}
	printf("%lld",sum);
	return 0;
} 
