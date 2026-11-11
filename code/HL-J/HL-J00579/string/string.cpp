#include <bits/stdc++.h>
using namespace std;
string s;
int n;
int main ()
    {
    
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	cin>>n;
	int j=0;
	for (int i=1;i<=n;i++)
		{
		int a;
		char c;
		cin>>a>>c;
		for (int k=1;k<=a;k++)
			{
			s+=c;
			j++;
			}
		}
	long long ans=0;
	if (j%2==0)
		{
		int l=0,r=s.size()-1;
		while (l<r)
			{
			if (s[l]!=s[r]) ans++;
			l++;r--;
			}
		cout<<ans;
		return 0;
		}
	else 
		{
		int l=0,r=s.size()-1;
		while (l!=r)
			{
			if (s[l]!=s[r]) ans++;
			l++;r--;
			}
		cout<<ans;
		return 0;
		}
    return 0;
    }
