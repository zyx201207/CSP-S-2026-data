#include <bits/stdc++.h>
using namespace std;
int n,num;
string s;
int main()
{
	freopen("string.in","r",stdin);
   	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
	    long long a;
	    char c;
		cin>>a>>c;
	    for(int i=1;i<=a;i++)
	    {
	    	s+=c;
		}
	}
	string b=s;
	reverse(s.begin(),s.end());
	
	for(int i=0;i<s.size()/2;i++)
	{
		if(s[i]!=b[i])
		{
			num++;
		}
	}
	cout<<num;
	return 0;
}
