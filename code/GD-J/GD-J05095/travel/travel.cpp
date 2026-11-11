#include <bits/stdc++.h>
using namespace std;

int stn(string n)
{
	int ans = 0;
	if (n.size()==1) ans += (n[0]-'0');
	else
		for (int i = 0;i < n.size();i++)
		{
			ans = ans * 10 + (n[i] - '0');
		}
	return ans;
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	string a1,b1;
	cin >> a >> a1 >> b >> b1;
	if (a == b)
	{
		cout << 1;
		string pos1 = a1.substr(0,2);
		int posa = stn(pos1);
		string pos2 = b1.substr(0,2);
		int posb = stn(pos2);
		if (posa == posb)
		{
			cout << 1;
			char aa = a1[2];
			char bb = b1[2];
			if ((aa>='A'&&aa<='C'&&bb>='A'&&bb<='C')||(aa>='D'&&aa<='E'&&bb>='D'&&bb<='E'))
			{
				cout << 1;
				if (abs(int(aa-bb)) == 1) cout << 1;
				else cout << 0;
				return 0;
			}
			else
			{
				cout << "00";
			}
		}
		else
		{
			cout << "000";
		}
	}
	else
	{
		cout << "0000";
		return 0;
	}
	return 0;
}
