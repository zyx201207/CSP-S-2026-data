#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	string s;
	long long n,sum=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int a;
		cin>>a;
		string c;
		cin>>c;
		while(a>0)
		{
			s+=c;
			a--;
		}
	}
	int a=s.size();
    for(int i=0;i<s.size()/2;i++)
    {
    	if(s[i]!=s[a-i-1])
    	{
    	    sum++;
    	}
    }
    cout<<sum;
	return 0;
}
