#include<bits/stdc++.h> 
using namespace std;
const int N=2e5+10;
string s,s1,s2,s3,x,y;
long long a,b=0,c=0,d,n;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n; 
	while(n--)
	{
		cin>>a>>x;
		for(int i=0;i<a;i++)
		{
			s=s+x;
		}
	}
	long long j=s.size();
	s1=s.substr(0,j/2);
	reverse(s.begin(),s.end());
	for(int i=0;i<j/2;i++)
	{
		if(s[i]!=s1[i]) c++;
	}
	cout<<c;
	return 0;
 } //2 2 a 3 a 3 2 a 2 b 1 c 6 1000000000 a 1000000000 a 1000000000 a 1000000000 b 1000000000 b 1000000000 b
