#include<bits/stdc++.h>
using namespace std;

bool a[4] = {0,0,0,0};
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2)
	{
		a[0] = 1;
		if((s1[0] == s2[0])|| (s1[1] == s2[1]))
		{
			a[1] = 1;
			if(s1[2] >= 'D' || s2[2] >= 'D' &&s1[2] <= 'C' || s2[2] <= 'C')
			{
				a[2] = 1;
				if((s1[2]=='F'||s2[2]=='D')&&(s1[2]=='C'||s2[2]=='B')&&(s1[2]=='B'||s2[2]=='A')){
					a[3] = 1;
				}
				else{cout << 1110;return 0;}
			}
			else{cout << 1100;return 0;}
		}
		else{cout << 1000;return 0;}
	}
	
	
	

	
	for(int i = 0;i < 4;i++)
		cout << a[i];
	
	
	
	return 0;
}
