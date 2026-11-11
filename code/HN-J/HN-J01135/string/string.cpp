#include <bits/stdc++.h>
using namespace std;
int n,cnt=0,x,y,sum;
char s;
string s1; 
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i=1;i<=n;i++)
	{
		cin >> x >> s;
		sum += x; 
		for (int i=1;i<=x;i++)
		{
		    s1 += s;
		  
		}
	}
	y = sum+1;
	for (int i=1;i<=s1.size()-1;i++)
	{
		if (s1[i]!=s1[sum-i])
		{
			 cnt++;
		}
		else  
		{
			continue; 
		}
	}
	cout << cnt << endl;
	return 0;
}
