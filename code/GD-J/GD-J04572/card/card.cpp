#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m,a[N],place[N],nowsum=0,surv[N],putplace[N],output[N];//place[i]记录点色i所在位置，putplace[i]表示第i位置对应的a中的下标 
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=m;i++)
	{
		memset(place,0,sizeof(place));
		memset(putplace,0,sizeof(putplace));
		memset(surv,0,sizeof(surv));
		nowsum=0;
		for(int j=i;j<=n;j++)
		{
			if(place[a[j]])
			{
				for(int k=place[a[j]]+1;k<=nowsum;k++)
				{
					place[a[putplace[k]]]=0;
					surv[putplace[k]]=0;
					putplace[k]=0;
				}
				nowsum=place[a[j]];
				surv[putplace[nowsum]]=0;
				putplace[nowsum]=j;
			}
			else
			{
				place[a[j]]=++nowsum;
				surv[j]=1;
				putplace[nowsum]=j;
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(surv[i])
			{
				output[a[i]]++;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<output[i]<<" ";
	}
}
