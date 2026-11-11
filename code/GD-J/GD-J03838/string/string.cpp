#include <bits/stdc++.h>
using namespace std;
int n,a,sum=0,num;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	char c,k;
	string s;
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> a >> c;
		for (int j = 1;j <= a;j++)
		{
			s += c;
		}
	}
	for (int i = 0;i < s.length()/2;i++)
	{
		if (s[i] == s[s.length()-i-1])
		{
			sum++;
		}
	}
	if (sum == s.length()/2)
	{
		cout << 0;
		return 0;
	}
	num = 0;
	k = s[s.length()/2];
    for (int j = 0;j < s.length();j++)
	{
		
	    for (int i = 0;i < s.length();i++)
     	{
    		if (i != s.length()/2 && s[i] == k)
		    {
		    	char x = s[s.length()-i-1];
			    s[s.length()-i-1] = k;
		    	k = x;
		    	num++;
	    	}
	    }
    }
	cout << num;
	return 0;
}
	
