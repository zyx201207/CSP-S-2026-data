#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char f,g,h,j,w,x;
	int a[30];
	for(int i=1;i<=30;i++)
	{
		cin>>a[i];
		if(a[1]+a[2]<17&&a[8]+a[9]<17)
		{
		if(a[1]+a[2]==a[8]+a[9])
		{
			f='1';
		}
		else 
		{
			f='0';
		}
		}	
		//同一节车厢
		else if(a[4]+a[5]==a[11]+a[12])
		{
		g='1';
		}
		else if(a[4]+a[5]!=a[11]+a[12])
		{
		g='0';
		}
		//同一排
		w=a[6];
		x=a[13];
		if(w=='D'||x=='D')
		{
			if(w=='F'||x=='F')
			{
				h='1';
			}
			else 
			{
				h='0';
			}	
		}
		else if(w !='D'||x !='D')
		{
			if(w=='F'||x=='F')
			{
				h='0';
			}
		}
		else if(w !='D'||x !='D'||w!='F'||x!='F')
		{
			h='1';
		}	
		//过道的同一侧
		else if(w+1==x||w-1==x)
		{
		j='1';
		}
		else if(w+1!=x||w-1!=x)
		{
		j='0';
		}
		//并且相邻
	}
	cout<<f<<g<<h<<j<<"1111";
	return 0;
}
