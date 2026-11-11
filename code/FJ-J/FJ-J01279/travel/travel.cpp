#include<bits/stdc++.h>
using namespace std;//100
int main()
{
	//freopen("travel1.in","r",stdin);
	//freopen("travel1.out","w",stdout);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int rp=114514;
	string a1,b1,a2,b2;
	cin>>a1>>b1>>a2>>b2;
	if(a1==a2)
	{
		cout<<1;
		if(b1[0]==b2[0]&&b1[1]==b2[1])
		{
			cout<<1;
			int s1=0,s2=0;
			if(b1[2]<='C') s1++;
			else s2++;
			if(b2[2]<='C') s1++;
			else s2++;
			if(s1&&s2) cout<<"00";
			else
			{
				cout<<1;
				if(abs(b1[2]-b2[2])==1&&(!((b1[2]=='C'&&b2[2]=='D')||(b2[2]=='C'&&b1[2]=='D'))))
				{
					cout<<1;
				}
				else cout<<0;
			}
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
} //初一9A要饿晕！！！饿不思蜀！！！

 
