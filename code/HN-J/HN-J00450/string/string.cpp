#include <cstdio> 
using namespace std;
int a[200005];
char b[200005];
int min(int x,int y)
{
	if(a[x]<a[y])return x;
	else if(a[x]>a[y])return y;
	else return -1;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d %c",&a[i],&b[i]);
	}
	
	long long cut=0;
	int r=1,l=n;
	if(n==1)
	{
		printf("0");
			fclose(stdin);
			fclose(stdout);
		return 0;
	}
	for(;;)
	{
		if(l-r==1)
		{
			if(b[r]==b[l])
			{
				break;
			}
			else if(a[r]==a[l])
			{
				cut+=a[r];
				printf("%lld",cut);
				break;
			}
			else
			{
				cut+=a[min(r,l)];
				printf("%lld",cut);
				break;
			}
		}
		if(min(r,l)==r)
		{
			if(b[r]==b[l])
			{
				a[l]-=a[r];
				r++;
			}
			else
			{
				a[l]-=a[r];
				cut+=a[r];
				r++;
			}
		}
		else if(min(r,l)==l)
		{
			if(b[r]==b[l])
			{
				a[r]-=a[l];
				l--;
			}
			else
			{
				a[r]-=a[l];
				cut+=a[l];
				l--;
			}
		}
		else
		{
			if(b[r]==b[l])
			{
				l--;
				r++;
			}
			else
			{
				cut+=a[l];
				r++;
				l--;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
