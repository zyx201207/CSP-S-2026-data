//GZ-J00597 六盘水市第二十四中学 王轩宇
#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long a,c,d=1,e=0,t,s,r;
	cin>>a>>c;
	long long b[a+5];
	for(int i=1;i<=a;i++)
	{
		cin>>b[i];
	}
	for(int i=1;i<=a;i++)
	{
		for(int j=i;j<=a;j++)
	    {
	    	if(b[j]>b[j+1]);
	    	{
	    		s=b[j];
	    		b[j]=b[j+1];
	    		b[j+1]=b[j];
			}
	    }
	}
	while(d<c)
	{
		for(int i=1;i<a;i++)
		{
			t=b[d]&b[d+i];
			e=max(t,e);
			if(b[d]<e)
			{
				r=i;
				b[d]=e;
			}
	    }
			s=min(b[d],b[r+d]);
			b[r+d]=0;
		d++;
	}
	cout<<e;
	return 0;
}

