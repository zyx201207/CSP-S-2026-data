#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

    long long n,m,tsg;
    cin>>n>>m;
    long long a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
//	for(int t=0;t<n;t++)
//	{
//		for(int j=0;j<n-1;j++)
//		{
//			if(a[j]<a[j+1])
//			{
//				tsg=a[j];
//				a[j]=a[j+1];
//				a[j+1]=tsg;
//			}
//		}
//	}
	int s[n]={0};
	int vv; 
	for(int y=0;y<n;y++)//Ä¿±êÖµ 
	{
		for(int u=0;u<n;u++)
		{
			vv=m-a[y]+a[u];
			if((a[y]>=a[u])&&(vv>=0))
			{
				m=vv;
				s[y]++;
			}
		}
		
	}
	int zzz=s[0];
	for(int i=1;i<n;i++)
	{
		if(s[i]>zzz)
		{
			zzz=s[i];
		}
	}
	cout<<zzz+1;


	fclose(stdin);
	fclose(stdout);
	return 0;
}
