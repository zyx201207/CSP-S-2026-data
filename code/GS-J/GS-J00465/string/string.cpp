#include<bits/stdc++.h>
using namespace std;
struct S
{
	string word;
	long long int c;
}a[100000005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long int n;
	string s;
	cin>>n;
	int k=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].c>>a[i].word;
		for(int j=0;j<a[i].c;j++)
		{
			s+=a[i].word;
		}
		k+=a[i].c;
	}
	k--;
	int ans=0;
	for(int i=0;i<s.size();i++)
	{
		if(i==k)
		{
			break;
		}
		else if(s[i]==s[k])
		{
			k--;
			continue;
		}
		else
		{
			k--;
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
