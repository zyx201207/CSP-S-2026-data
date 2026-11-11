#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int m,n;
	cin>>m>>n;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i];
	}
	int cnt=0;
	int k=0;
	int bnt=0;
	int ant=0;
	int minn=-10;
	int j=1+bnt;
	for(int i=1;i<=m;i++)
	{
		k++;
		j=1+bnt;
		while(j<=m)
		{
			for(j=1+bnt;j<=bnt+k+1;j++)
			{
				if(j+1<=n)
				{
					for(int o=1+bnt;o<=bnt+k;o++)
					{
						if(1+bnt+k>n)
						{
							break;
						}
						cnt=cnt+abs(abs(a[o+1])-abs(a[o]));
						ant++;
					}
					
				}
				if(j>n)
				{
					break;
				}bnt++;
				
				if(cnt<=m&&ant>minn)
				{
					
					minn=ant;
				}
			ant=1;
			}
			
			
		}
		bnt=0;cnt=0;
	}
	cout<<minn;
	return 0;
}
