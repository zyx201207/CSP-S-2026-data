#include<bits/stdc++.h>
using namespace std;
int main()
{
   freopen("crystal.in","r",stdin);
   freopen("crystal.out","w",stdout);
   long long a[50010],n;
   long long m;
   cin>>n>>m;
   for(int i=0;i<n;i++)
   {
   	cin>>a[i];
   }
   sort(a,a+n);
   if(n<=16)
   {
   	 int q=0,c=0,p=0,o=0;;
   	 for(int i=0;i<n;i++)
   	 {
   	 	for(int j=i;j<n-1;j++)
   	 	{
   	 		
			q=q+(o+1)*(a[j+1]-a[j]);
   	 		c++;
   	 		o++;
   	 		if(q>m)
   	 		{
   	 			p=max(p,c);
   	 			q=0;
   	 			c=0;
   	 			o=0;
			}
		}
		q=0;
   	 	c=0;
   	 	o=0;
	 }
	 cout<<p;
     fclose(stdin);
	 fclose(stdout);
   }
   long long zong=0;
   int cha,yin=1,w=1,sum=0;
   cha=a[1]-a[0];
   for(int i=0;i<n;i++)
   {
   	  zong=zong+cha*yin;
   	  yin+=w;
   	  w++;
   	  sum++;
   	  if(zong>m)
   	  {
   	  	cout<<" "<<sum<<" ";
   	    fclose(stdin);
        fclose(stdout);
        return 0;
	  }
   }
   fclose(stdin);
   fclose(stdout);
   return 0;
} 
