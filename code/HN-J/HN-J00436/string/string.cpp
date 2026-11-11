#include <cstdio>
using namespace std;
long long l[200005]={};
char l2[200005]={};

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,i,j;
	long long ct=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%lld %c",&l[i],&l2[i]);
	i=1;j=n;
	while(i<j)
	{
		if(l2[i]==l2[j])
		{
			if(l[i]==l[j])
			{
				i++;
				j--;
			}
			else
			{
				if(l[i]>l[j])
				{
					l[i]-=l[j];
					j--;
				}
				else
				{
					l[j]-=l[i];
					i++;
				}
			}
		}
		else
		{
			if(l[i]==l[j])
			{
				ct+=l[i];
				i++;
				j--;
			}
			else
			{
				if(l[i]>l[j])
				{
					ct+=l[i]-l[j];
					l[i]-=l[j];
					j--;
				}
				else
				{
					ct+=l[j]-l[i];
					l[j]-=l[i];
					i++;
				}
			}
		}
	}
	printf("%lld",ct);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
