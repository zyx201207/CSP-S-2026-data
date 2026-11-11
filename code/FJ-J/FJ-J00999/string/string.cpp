#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,i,j;
	long long a;
	char c;
	string s;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a>>c;
		for(j=1;j<=a;j++)
		s+=c;
	}
	long long cnt=0,l=0,len=s.size(),r=len-1;
	while(l!=r)
	{
		if(s[l]!=s[r])
		cnt++;
		l++,r--;
	}
	cout<<cnt;
	return 0;
}
