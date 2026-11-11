#include<bits/stdc++.h>
using namespace std;
int n,cnt;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x;
		char y;
		cin>>x>>y;
		for(int j=1;j<=x;j++)
		{
			s+=y;	
		}
	}
	long long m=(s.size()+1)/2;
	int j=m-1;
	if(s.size()%2==0)
	{
		j++;
	}
	for(int i=1;i<=s.size(),j>=0;i++,j--)
	{
		if(s[i]!=s[j])
		{
			cnt+=1;
		}                    
	}
	cout<<cnt;
	return 0;
}