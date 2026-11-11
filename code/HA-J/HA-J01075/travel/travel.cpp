#include<bits/stdc++.h>
using namespace std;
string s[10];
int cnt1,cnt2;
char ch1[5],ch2[5];
void solve()
{
	for(int i=1;i<=4;i++)
	{
		cin>>s[i];
	}
	for(char ch:s[2])
	{
		cnt1++;
		ch1[cnt1]=ch;
	}
	for(char ch:s[4])
	{
		cnt2++;
		ch2[cnt2]=ch;
	}
	if(s[1]!=s[3])
	{
		cout<<"0000\n";
	}
	else
	{
		if(ch1[1]!=ch2[1]||ch1[2]!=ch2[2])
		{
			cout<<"1000\n";
		}
		else
		{
			if(ch1[3]<='C'&&ch2[3]>='D'  ||  ch1[3]>='D'&&ch2[3]<='C')
			{
				cout<<"1100\n";
			}
			else
			{
				if(max(ch1[3],ch2[3])-min(ch1[3],ch2[3])>1)
				{
					cout<<"1110\n";
				}
				else
				{
					cout<<"1111\n";
				}
			}
		}
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int T;
	T=1;
	while(T--)
	{
		solve();
	}
	return 0;
}
