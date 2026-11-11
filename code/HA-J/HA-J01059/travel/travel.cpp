#include<bits/stdc++.h>
using namespace std;
int main()
{
	openfile("travel.in");
	char c1[10],s1[10],c2[10],s2[10],h1,h2;
	int p1,p2,t1,t2;
	cin>>c1>>s1>>c2>>s2;
	t1=(c1[0]-'0')*10+(c1[1]-'0');
	t2=(c2[0]-'0')*10+(c2[1]-'0');
	p1=(s1[0]-'0')*10+(s1[1]-'0');
	p2=(s2[0]-'0')*10+(s2[1]-'0');
	h1=s1[2];h2=s2[2];
	if(t1==t2)
	{
		if(p1==p2)
		{
			if(h1<='C'&&h2<='C')
			{
				if((h1>h2?h1-h2:h2-h1)==1) cout<<"1111";
				else cout<<"1110";
			}
			else if(h1>='D'&&h2>='D') cout<<"1111";
			else cout<<"1100";
		}
		else cout<<"1000";
	}
	else cout<<"0000";
	putfile("travel.out");
	return 0;
}
