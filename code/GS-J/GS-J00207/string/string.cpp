#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int di=0;
	long long n,x=0;
	long long a,af=0;
	string s1;
	cin >> n;
	char c[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a >> c[i];
		if(di!=1){
		    for (int j = 1; j <= a; j++)
		    {
			    s1+=c[i];
		    }
	    }
		af+=a;
		if(af>=2000000000){
			di=1;
		}
	}
	string s2;
	if(di!=1){
	    for (int i = s1.size()-1; i >= 0; i--)
	    {
		    s2+=s1[i];
	    }
	}
	if(s1==s2)
	{
		cout << 0;
		return 0;
	}
	if(di!=1){
	    for (int i = 0; i <= af/2-af%2; i++)
	    {
		    if(s1[i]!=s2[i])
		    {
			    x++;
		    }
	    }
	}
	if(di){
	for (int i = 0; i < n; i++)
	{
		s1+=c[i];
	}
	for (int i = n-1; i >= 0; i--)
	{
		s2+=c[i];
	}
	if(s1==s2)
	{
		cout << 0;
		return 0;
	}
	for (int i = 0; i <= n/2-n%2; i++)
	{
		if(s1[i]!=s2[i])
		{
			x++;
		}
	}
	cout << x*1000000000;
	return 0;
	}
	cout << x;
	return 0;
}
