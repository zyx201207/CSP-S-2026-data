//GZ-J00044 贵州市花溪区实验中学 游梓一
#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500000],flo[500000],dsi=0,s[300000];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=0;i<n;i++)
	{
		memset(flo,0,sizeof(flo));
		dsi=0;
		for(int l=i;l<n;l++)
		{
			for(int j=0;j<=dsi;j++)
			{
				if(j==dsi)
				{
					flo[j]=a[l];
					dsi++;
					break;
				}
				if(flo[j]==a[l])
				{
					for(int p=j+1;p<dsi;p++)
					{
						flo[p]=0;
					}
					dsi=j+1;
					break;
				}
			}
			
		}
		for(int l=0;l<dsi;l++)
			{
				s[flo[l]-1]++;
			}
	}
	for(int i=0;i<m;i++)
	{
		printf("%d ",s[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
