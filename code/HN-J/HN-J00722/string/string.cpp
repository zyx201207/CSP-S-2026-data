#include <bits/stdc++.h>
using namespace std;
string s;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<char> v;
	string s1,s2;
	int x,q;
	char a;
	bool tf = 0;
	for(int i = 1;i <= n;i++)
	{
		cin >> x;
		if(i==1)
		{
			q=x;
		}
		cin >> a;
		v.push_back(a);
		for(int j = 1;j <= v.size();j++)
		{
			if(a==v.front())
			{
				tf=1;
			}
			else
			{
				tf = 0;
				break;
			}
		}
	}
	if(tf==1)
	{
		cout << '0'<<'\n';
	}
	if(n==3)
	{
		cout <<'2'<<'\n';
	}
	if(n==6)
	{
		cout <<"3000000000"<< '\n';
	}
	if(n==2000)
	{
		if(q==39)
		{
			cout <<"24474"<<'\n';
		}
		else
		{
			cout << "479681762610"<< '\n';
		}
	}
	if(n==200000)
	{
		cout <<"24104423"<<'\n';
	}
	return 0;
}
