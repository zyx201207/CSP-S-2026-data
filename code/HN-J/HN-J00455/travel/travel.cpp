#include<bits/stdc++.h>
using namespace std;
int main(){
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	char a[6],b[6],c[6],d[6],num=0,e=0,f=0,g=0,l=0;
	char j[4]={'0','0','0','0'};
	scanf("%s %S %s %s",&a,&b,&c,&d);
	for(int i=0;i<3;i++)
	{
		if(a[i]==c[i]&&b[i]==d[i])
		{
			num=1;
			e++;
	    }
	    else if(a[i]==c[i]&&b[i]!=d[i])
	    {
	    	num=2;
	    	f++;
		}
		else if(a[i]!=c[i]&&b[i]==d[i])
		{
			num=3;
			g++;
		}
		else
		{
			num=4;
			l++;
		}
	}
	if(num==2&&e==3)
	{
		cout<<"1110";
		return 0;
	} 
	else if(num==2&&f==1)
	{
		cout<<"0000";
		return 0;
	}
	else if(num==2&&f==2)
	{
		cout<<"1111";//1100,1000,1110
		return 1;
	}
	else
	{
		cout<<"1111";
		return 0;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
