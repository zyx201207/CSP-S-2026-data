#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c1,c2;
	string s1,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	int p1 = (s1[0]-'0')*10+(s1[1]-'0');
	int p2 = (s2[0]-'0')*10+(s2[1]-'0');
	cout << (c1==c2);
	cout <<((c1==c2)&&(p1==p2));
	cout <<((c1==c2)&&(p1==p2)&&((s1[2]<'D'&&s2[2]<'D')||(s1[2]>'C'&&s2[2]>'C')));
	if((s1[2]=='D'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='D'))
	{
		cout << 0;
	}
	else if(abs(int(s1[2])-int(s2[2]))==1&&(c2==c1)&&(p1==p2))
	{
		cout << 1;
	}
	else
	{
		cout << 0;
	}
	return 0;
}