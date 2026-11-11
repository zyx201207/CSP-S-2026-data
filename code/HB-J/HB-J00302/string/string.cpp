#include <bits/stdc++.h>
using namespace std;
string s,z,spie;
long long shu[1000005],ans,minans,c;
bool pandi(string x;)
{
	for(int i=0;i<=x.length()-1;i++)
	{
		if(x[i]==x[x.length()+1-i])
		else
			return False;
	}
	return True;
};
long long n,duoyude;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i=1;i<=n;i++)
	{
		cin >> shu[i] >> z[i-1];
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<=shu[i]-1;j++)
		{
			s[c]=z[i-1];
			++c;
		}
	}
	if(pandi(s))
	{
		cout << "0" << "\n";
		return 0;
	}
	minans = 9999999;
	for(int i=1;i<=n;i++)
	{
		spie =s;
		duoyude = spie[spie.length()];
		for (int j=n-i-1;j<=spie.length();j++)
		{
			spie[j+1] = spie[j];
		}
		spie[n-i-1] = duoyude;
		if(pandi)
			ans = spie.length()-(n-i-1);
			minans = min(ans,minans);
	}
	cout << minans << "\n";
	return 0;
}
