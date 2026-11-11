#include<bits/stdc++.h> 
using namespace std;
int c,t;
long long x[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t)
	{
		t--;
		long long n,d;
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++)
			scanf("%lld",&x[i]);
		if(n==1||n==2)
			printf("%d",0);
		else{
			printf("%lld",(n-2)*(n-1)/2);
		} 
	}
}
