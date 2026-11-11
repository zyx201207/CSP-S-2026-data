#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s="";
	for(long long i=0;i<n;i++)
	{
		int a;
		char l;
		cin>>a;
		cin>>l;
		for(int j=0;j<a;j++)
		{
			s+=l;
		}
	}
	long long slen=s.size();
	long long backi=slen-1,ans=0;
	for(long long i=0;i<slen/2;i++)
	{
		if(s[i]!=s[backi])
		{
			ans++;
		}
		backi--;
	}
	cout<<ans;
	return 0;
}
