#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int a=0;
	if(c1==c2)
	{
		cout<<1;
		a++;
		if(s1[1]==s2[1] && s1[2]==s2[2])
		{
			cout<<1;
			a++;	
			if((s1[3]>='D' && s2[3]>='D') || (s1[3]<'D' && s2[3]<'D'))
			{
				cout<<1;
				a++;
					if((s1[3]-'A')-(s2[3]-'A')==1 || (s2[3]-'A')-(s1[3]-'A')==1)
					{
						cout<<1;
						a++;
					}
			}
		}
	}
	for(;a<4;a++) cout<<0;
	return 0;
 } 
