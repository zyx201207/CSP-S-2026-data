#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	scanf("%d%lld",&n,&m);
	int mmax=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		if(a[i]<a[1]+m)
		{
			mmax++;
		}
	}
	printf("%d",mmax);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
