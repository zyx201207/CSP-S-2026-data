#include<bits/stdc++.h>
using namespace std;
int main()
{

	freeopen("card.in","r",stdin);
	freeopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[500010],b[500010];
    int sum=0;
    for(int i=0;i<n;i++)
    {
    	cin>>a[i];
    	a[i]=b[i];
	}
	 for(int i=0;i<n;i++)
    {
    	
	
	  for(int j=0;j<i;j++)
     {
    	if(a[i]==b[j])
    	{
            for(int v=0;v<j;v++)
          {
    	      b[v]=0;
          }
		}
	  }
	  sum++;
   }
	  for(int i=0;i<n;i++)
    {
    	if(b[i]!=0)
    	{
    		cout<<b[i];
		}
	}
	cout<<sum;
	return 0;
}
