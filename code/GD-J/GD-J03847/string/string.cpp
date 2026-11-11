#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.in","w",stdout);
	int n;
	cin>>n;
	string s="";
	for(int i=0;i<n;i++)
	{
		int a;
		string S;
		cin>>a>>S;
		for(int i=0;i<a;i++)
		{
			s+=S;
		}
	}
	long long cnt=0;
	for(int i=0,j=s.size()-1;i+1!=j;i++,j--)
	{
		if(s[i]!=s[j])
		{
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
