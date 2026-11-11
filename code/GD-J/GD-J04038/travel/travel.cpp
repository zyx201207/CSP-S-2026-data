#include<bits/stdc++.h>
using namespace std;
int main()
{
	 
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	bool f1=0,f2=0,f3=0,f4=0;
	if(a==c)
	{
		f1=1;
		string e="",f=""; 
		e+=b[0],e+=b[1],f+=d[0],f+=d[1];
		//cout<<e<<' '<<f<<endl;
		if(e==f)
		{
			f2=1;
			
			char g=b[2],h=d[2];
		//	cout<<g<<' '<<h<<endl;
			if((g>='A'&&g<='C'&&h>='A'&&h<='C')||(g>='D'&&g<='F'&&h>='D'&&h<='F'))
			{
				f3=1;
				if(abs(g-h)==1)
				{
					f4=1;
				}
			}
		}
	} 
	cout<<f1<<f2<<f3<<f4;
	
	return 0;
 } 
