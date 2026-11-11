#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	string ans="";
	bool f1=0,f2=0,f3=0;
	if(c1!=c2)
	{
		cout<<"0000"<<endl;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	else
	{
		ans+="1";
		f1=1;
	}
	string k1=s1.substr(0,2),k2=s2.substr(0,2);
	char r1=s1[2],r2=s2[2];
	if(f1)
	{
		if(k1==k2)
		{
			ans+="1";
			f2=1;
		}
		else ans+="0";
	}else
	{
		ans+="0";
	}
	if(f1&&f2)
	{
		if(r1>='A'&&r2<='C'||r1=='D'&&r2=='F')
		{
			ans+="1";
			f3=true;
		}else ans+="0";
	}else ans+="0";
	if(f1&&f2&&f3)
	{
		if(r1+1==r2||r2+1==r1||r1=='D'&&r2=='F'||r1=='F'&&r2=='D')
		{
			ans+="1";
		}else ans+="0";
	}else ans+="0";
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
