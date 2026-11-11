#include<bits/stdc++.h>
using namespace std;
long long n,a[1000005],sum;
char c[1000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		cin>>c[i];
	}
	int x=1,y=n;
	while(x<y)
	{
		if(c[x]!=c[y])
		{
			if(a[x]>a[y])
			{
				sum+=(a[y]);
				a[x]-=a[y];
				a[y]=0;
				y--;
			}
			else if(a[x]<a[y])
			{
				sum+=(a[x]);
				a[y]-=a[x];
				a[x]=0;
				x++;
			}
			else sum+=a[x],a[x]=0,a[y]=0,x++,y--;
		}
		else
		{
			if(a[x]>a[y])
			{
				a[x]-=a[y];
				a[y]=0;
				y--;
			}
			else if(a[x]<a[y])
			{
				a[y]-=a[x];
				a[x]=0;
				x++;
			}
			else x++,y--;
		}
	} 
	cout<<sum;
	return 0;
}
