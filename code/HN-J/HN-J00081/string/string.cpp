#include<bits/stdc++.h>
using namespace std;
int main()
{
   freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
     int n,z=0,s=0;
     cin>>n;
     int a[n+1];
     char c[n+1];
     int h;
     for(int i=1;i<=n;i++)
     {
     	cin>>a[i];
     	cin>>c[i];
     	s+=a[i];
	 }
	 char d[s+1];
	 int p=0;
    for(int i=1;i<=n;i++)
    {
    	h=a[i];
    	while(h!=0)
    	{
    		p++;
    		d[p]=c[i];
    		h--;
		}
	}
	if(s%2==0)
	{
		int k=1;
		int q=s/2;
		while(k<=q)
		{
			if(d[k]!=d[s])
			z++;
			k++;
			s--;
		}
	}
	else
	{
		int k=1;
		while(k<=s/2+1)
		{
			if(d[k]!=d[s])
			z++;
			k++;
			s--;
		}
	}
	 cout<<z;
	fclose(stdin);
fclose(stdout);
    return 0;
}
