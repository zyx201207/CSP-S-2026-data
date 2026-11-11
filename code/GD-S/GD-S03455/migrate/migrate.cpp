#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int c,q;
int n;
long long d,a[N],ans,js;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&q);
	while(q--)
	{
		scanf("%d",&n);
		scanf("%lld",&d);
		bool flag=true;
		long long x=0ll;
		for(int i=1; i<=n; i++)
		{
			scanf("%lld",&a[i]);
			if(x==0ll && i==2) x=abs(a[i]-a[i-1]);
			if(i>2 && x!=abs(a[i]-a[i-1])) flag=false;
		}
		if(flag)
		{
			long long cnt=d/(abs(a[2]-a[1]));
			if(cnt<2) printf("0\n");
			else printf("%lld\n",max(n-cnt*2+1,0ll));
			continue;
		}
	}
	return 0;
}
