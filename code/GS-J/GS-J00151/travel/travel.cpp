#include<bits/stdc++.h>
using namespace std;
int a[5],b[5],num[5];
int d(char x)
{
	if(x=='A') return 1;
	if(x=='B') return 2;
	if(x=='C') return 3;
	if(x=='D') return 4;
	if(x=='F') return 5;
}
int main()
{
	freopen ("travel.in","r",stdin);
	freopen ("travel.out","w",stdout);
	string c,s,c1,s1;
	cin >> c >> s >> c1 >> s1;
	a[3]=d(s[2]);
	b[3]=d(s1[2]);
	if(c==c1)
	{
		num[1]++;
		if(s[0]==s1[0]&&s[1]==s1[1])
		{
			num[2]++;
			if((a[3]<=3&&b[3]<=3)||((a[3]==4&&b[3]==5)||(a[3]==5)&b[3]==4))
			{
				num[3]++;
				if(a[3]-b[3]==1||b[3]-a[3]==1)
				{
					num[4]++;
				}
			}
		}
	}
	for(int i=1;i<=4;i++)
	{
		if(num[i]==1) cout << '1';
		else cout << '0';
	}
	return 0;
}
