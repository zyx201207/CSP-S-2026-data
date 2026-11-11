#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1==c2)
	{
		for(int i=0;i<2;i++)
		{
			if(s1[i]!=s2[i])
			{
				cout << "1000";
				return 0;
			}
		}
		char z1=s1[2],z2=s2[2];
		if(z1=='A'||z1=='B'||z1=='C')
		{
			if(z2=='A'||z2=='B'||z2=='C')
			{
				if(abs(z1-z2)==1) cout << "1111";
				else cout << "1110";
			}
			else cout << "1100";
		}
		else if(z1=='D'||z1=='E')
		{
			if(z2=='D'||z2=='E') cout << "1111";
			else cout << "1100";
		}
	}
	else cout << "0000";
	return 0;
}
