#include<bits/stdc++.h>
using namespace std;
string s;
int n;
long long ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int sum;
		char c;
		cin>>sum>>c;
		for(int j=1;j<=sum;j++)
		{
			s+=c;
		}
	}
	for(int i=0,j=s.length()-1;i<=s.length()/2-1;i++,j--)
	{
		if(s[i]!=s[j])
		{
			ans++;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
