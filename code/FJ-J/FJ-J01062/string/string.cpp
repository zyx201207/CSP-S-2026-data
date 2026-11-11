#include <bits/stdc++.h>
using namespace std;
int n,sum=0;
long long a;
string s,c;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>c;
		while(a--)
	    {
	        s+=c;
		}
	}
    for(int i=0;i<=s.length()/2;i++)
	{
	    if(s[i]!=s[s.length()-i-1])
	    {
	    	sum++;
		}
	}
	cout<<sum;
	return 0;
}
