#include <cstdio> 
using namespace std;
int i1[300005],ai[500005],a[500005];
int cz(int q,int x,int k)
{
	for(int i=q;i<=x;i++)
	{
		if(a[x]==k)return i;
	}
	return -1;
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",ai[i]);
	}
	for(int f=1;f<=n;f++)
	{
		int cut=n-f+1;
		int r=f;
		int l=1;
		int sum=0;
		while(cut>0)
		{
			a[l]=ai[r];
			sum++;
			cut--;
			if(cz(r,l,ai[r])!=-1)
			{
				l=cz(r,l,ai[r]);
			}
			l++;
			r++;
		}
		for(int i=1;i<=l-1;i++)
		{
			i1[a[i]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		printf("%d",i1[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
