#include<bits/stdc++.h>
using namespace std;
long long a[200010],n,cnt;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		char x;
		cin>>a[i]>>x;
		int tmp=a[i];
		while(tmp--)s+=x;
	}
	for(int i=0;i<s.size()/2;i++)
	{
		if(s[i]!=s[s.size()-i-1])cnt++;
	}
	cout<<cnt;
	return 0;
} 
