#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	int f1=0,f2=0,f3=0,f4=0;
	string f5="",f6="";
	f5+=s2[0]+s2[1];
	f6+=s4[0]+s4[1];
	if(s1==s3)
	{
		f1=1;
	}
	if(f5==f6 && f1==1)
	{
		f2=1;
	}
	char c1=s2[2],c2=s4[2];
	if(f2==1)
	{
		if((c1>='A' && c1<='C' && c2>='A' && c2<='C') || (c1>='D' && c1<='F' && c2>='D' && c2<='F'))
		{
			f3=1;
			if(c1>='D' && c1<='F' && c2>='D' && c2<='F')
			{
				f4=1;
			}
			else if(!((c1=='A' && c2=='C') || (c1=='C' && c2=='A')))
			{
				f4=1;
			}
			else
			{
				f4=0;
			}
		}
	}
	cout<<f1<<f2<<f3<<f4<<endl;
    return 0;
}
