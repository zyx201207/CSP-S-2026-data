#include <cstdio>
using namespace std;
int a[200005]={},max=0,n,m;
bool b[200005]={};

void search(int r,int s,int t)
{
	int i,sum;
	for(i=r;i<=n;i++)
	{
		if(b[i]==0)
		{
			b[i]=1;
			if(s==1)
				sum=a[i];
			else
				sum=t&a[i];
			if(s>=m)
			{
				if(sum>max)
					max=sum;
			}
			else
				search(i+1,s+1,sum);
			b[i]=0;
			sum=0;
		}
	}
	return;
}

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int i;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	search(1,1,0);
	printf("%d",max);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
