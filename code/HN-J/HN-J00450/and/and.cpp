#include <cstdio> 
using namespace std;
int n,m,a[200005],mxx=0;
bool b[200005];
void s(int x,int y)
{
	for(int i=1;i<=n;i++)
	{
		if(!b[i])
		{
			int g=y&a[i];
			b[i]=1;
			if(x==m)
			{
				if(g>mxx)
				{
					mxx=g;
				}
			}
			else
			{
				s(x+1,g);
			}
			b[i]=0;
		}
	}
	return ;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d %d",&n,&m);
	scanf("%d",&a[1]);
	int sum=a[1],maxx=0;
	for(int i=2;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(m==1)
		{
			if(maxx<a[i])
			{
				maxx=a[i];
			}
		}
		else if(m==n)
		{
			sum&=a[i];
		}
	}
	if(m==1)
	{
		printf("%d",maxx);
	}
	else if(m==n)
	{
		printf("%d",sum);
	}
	else
	{
		for(int f=1;f<=n;f++)
		{
			b[f]=1;
			s(2,a[f]);
		}
		printf("%d",mxx);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
