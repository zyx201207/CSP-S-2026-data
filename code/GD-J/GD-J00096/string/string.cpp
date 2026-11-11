#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s;
	long long l=0;
	while(n--)
	{
		int a;
		char c;
		cin>>a>>c;
		for(int i=1;i<=a;i++)
			s[l++]=c;
	}
	l--;
	long long cnt=0;
	for(int i=0,j=l;i<=j;i++,j--)
	{
		if(s[i]!=s[j])
			cnt++;
	}
	cout<<cnt;
	return 0;
}  
