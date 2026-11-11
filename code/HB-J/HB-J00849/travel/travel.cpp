#include<bits/stdc++.h>
using namespace std;
ints main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","W",stdout);
	long long c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2)
	{
		cout<<'0';
	}
	else
	{
		string ss1=s1.substr(0,2);
		string ss2=s2.substr(0,2);
		long long t1=(ss1[0]-'0')*10+(ss1[1]-'0');
		long long t2=(ss2[0]-'0')*10+(ss2[1]-'0');
		cout<<'1';
		if(t1==t2)
		{
			cout<<'1';
			char tt1=s1[2],tt2=s2[2];
			if((tt1=='A'||tt1=='B'||tt1=='C')&&(tt2=='A'||tt2=='B'||tt2=='C'))
			{
				cout<<'1';
				if((tt1=='A'&&tt2=='B')||(tt1=='B'&&tt2=='C')||(tt1=='B'&&tt2=='A')||(tt1=='C'&&tt2=='B'))
				{
					cout<<'1';
				}
				else cout<<'0';
			}
			if((tt1=='F'||tt1=='D')&&(tt2=='D'||tt2=='F'))
			{
				cout<<'1';
				cout<<'1';
			}
		}
		else
		{
		    cout<<'0';
		}
	}
	return 0;
}
