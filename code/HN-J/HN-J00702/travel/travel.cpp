#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	string e="0000";
	if(a==c) 
	{
		e[0]='1';
		if(b[0]==d[0]&&b[1]==d[1])
		{
			e[1]='1';
			bool flag1,flag2;
			if(b[2]>='A'&&b[3]<='C') flag1=1;
			else flag1=0;
			if(d[2]>='A'&&d[3]<='C') flag2=1;
			else flag2=0;	
			if(flag1==flag2)
			{
				e[2]='1';
				if(flag1==0) e[3]='1';
				else if(abs((int)d[2]-b[2])==1) e[3]='1';
			}		
		}
	}
	cout<<e<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
