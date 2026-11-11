#include<bits/stdc++.h>
using namespace std;
int main()
{ 
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
 long long a[500005],ge[500005]; 
	int n=0,cishu=0;
	//long long a[50005],ge[50005];²âÊÔÓÃ 
	long long  m=0,he;
	
	
	cin>>n;
	cin>>m;
	
	for(int i=1;i<=n;i++)
	{  
		cin>>a[i];
	}
	 
	sort(a+1,a+n+1);
	

		for(int i=n;i>=0;i--)
		{ 
			cishu+=1;
			he=0;
			for(int j=i;j>=0;j--)
			{
			if(he>=m)
				{
					if(he==m)
					{
					ge[cishu]=i-j;	
					
					}
						
				continue;	
				}
			he+=a[i]-a[j]; 
			
				
			
			}
		}
		int maxge=0;	
	for(int i=1;i<=cishu;i++)
	{
		if(ge[i]>maxge)
		{
			maxge=ge[i];
		}
}
cout<<maxge;


	return 0;
}
