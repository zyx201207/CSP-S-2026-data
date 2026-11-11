//GZ-J00597 六盘水市第二十四中学 王轩宇
#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long a,b,r,z=0;
	cin>>a>>b;
	long long c[a+5],d[100000005],e[500000]={0};
	for(int i=1;i<=a;i++)
	{
		cin>>c[i];
	}
	for(int i=1;i<=b;i++)
	{
		for(int j=i;i<=a;j++)
	    {
	    	d[j]=c[j];
	    	e[c[j]]++;
	    	if(e[c[j]]>=2)
	    	{
	    		r=j;
			}
	    }
	    for(int j=r;j<=a;j++)
	    {
	    	z+=c[j];
		}
		if(i==b)
		{
			cout<<z;
		}
		cout<<z<<" ";
		z=0;
	}
	return 0;
}

