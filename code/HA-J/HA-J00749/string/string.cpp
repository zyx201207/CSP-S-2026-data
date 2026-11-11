#include<bits/stdc++.h>
using namespace std;
long long n,a,ans=0;
char c;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	string s;
	int x=0;
	for(int i=0;i<n;i++)
	{
		cin>>a>>c;
		x+=a;
		while(a)
		{
			s+=c;
			a--;
		}
	}

		int l=0;
		int r=x-1;
	while(l!=r)
	{
		if(s[l]!=s[r])
		{
			ans++;
		}
		l++;
		r--;
	}	
	cout<<ans;
	return 0;
}
