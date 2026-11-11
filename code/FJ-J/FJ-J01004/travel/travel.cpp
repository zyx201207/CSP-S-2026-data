#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	int a,a1,a2,a3=0;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1=c2) a+=1;
	for(int i=1;i<=3;i++)
	{
		if(s1[1]=s2[1] && s1[2]=s2[2]) a1+=1;
		if(s1[3]-"A"=s2[3])
		{
			a2+=1;
			a3+=1;
			break;
		}
		else if(s1[3]-"B"=s2[3])
		{
			a2+=1;
		}
		else
		{
			continue;
		}
	}
	cout << a << a1 << a2 << a3;
	return 0;
}
