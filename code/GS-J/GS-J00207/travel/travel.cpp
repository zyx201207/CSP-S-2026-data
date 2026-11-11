#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	int a[10]={0};
	if(c1==c2)
	{
		a[1]=1;
	}
	int x1=0,x2=0;
	for (int i = 0; i < s1.size()-1; i++)
	{
		x1+=s1[i]-'0';
		x2+=s2[i]-'0';
		x1*=10;
		x2*=10;
	}
	if(x1==x2&&a[1]==1)
	{
		a[2]=1;
	}
	if((s1[2]>'C'&&s2[2]>'C'||s2[2]<'D'&&s1[2]<'D')&&a[2]==1&&a[1]==1)
	{
		a[3]=1;
	}
	if((s1[2]-s2[2]==1||s1[2]-s2[2]==-1)&&a[2]==1&&a[3]==1&&a[1]==1)
	{
		a[4]=1;
	}
	for (int i = 1; i < 5; i++)
	{
		cout << a[i] << ' ';
	}
	return 0;
}
