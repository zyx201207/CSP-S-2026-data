#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	string k1=s1.substr(0,2);
	string k2=s2.substr(0,2);
	char m1=s1[2];
	char m2=s2[2];
	
	if(c1==c2) 
	{
		if(k1==k2)
		{
			if((m1<='C'&&m2<='C')||(m1>='D'&&m2>='D'))
			{
				if(abs(int(m1-m2))==1) cout<<"1111";
				else cout<<"1110";
			}
			else cout<<"1100";
		} 
		else cout<<"1000";
	} 
	else cout<<"0000";
	
	return 0;
}
