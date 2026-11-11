#include<bits/stdc++.h>
using namespace std;
string s="ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ";
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	long long idx=0;
	long long cnt=0;
	while(n--)
	{
		long long a;
		char c;
		cin>>a;
		cin>>c;
		for(int i=1;i<=a;i++)
		{
			s[idx]=c;
			//cout<<s[idx];
			idx++;
			//cout<<idx;
		}
		cnt+=a;
	}
	//cout<<s;
	long long l=0;
	long long r=cnt-1;
	long long sum=0;
	while(l<=r)
	{
		if(s[r]!=s[l])
		{
			sum++;
		}
		l++;
		r--;
	}
	cout<<sum<<endl;
	return 0;
}
