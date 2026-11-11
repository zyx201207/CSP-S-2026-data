#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	//foropen("cs-1.out","w",stdout);
	freopen("card.out","w",stdout);
	int n,m,j;
	cin>>n>>m;
	int s[(n+10)],w[(n+10)],js[(m+1)];
	
	for(int i2=0;i2<n;i2++)
	{
		cin>>s[i2];
	}
	for(int i7=0;i7<=n;i7++)
	{
		js[i7]=0;
	}
	
	
	for(int i8=0;i8<n;i8++)
		{

	
	for(int i=0;i<=n;i++)
	{
		w[i]=s[i];
		j=s[i];
		for(int i3=0;i3<i;i3++)
		{
			if(w[i3]==j)
			{
			
				for(int i4=i3;i4<=n;i4++)
				{
					w[i4]=0;
					//cout<<" K ";
					
				}
			}
		}
	
	
	for(int i5=1;i5<n;i5++)
	{
		for(int i6=0;i6<=n;i6++)
		{
			if(w[i6]==i5)
			{
			js[i5]=js[i5]+1;
			}
		}
	}
	
	}
	
		}
		
		
	for(int i9=1;i9<=(m+1);i9++)
	{
			cout<<js[i9]<<" ";
		
	}
	
	return 0;
}
