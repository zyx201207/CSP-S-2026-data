#include<bits/stdc++.h>
using namespace std;
const int N=1e9+10;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s;
	long long o=0;
	for(int i=1;i<=n;i++)
	{
		int num;
		cin>>num;
		char t;
		cin>>t;
		for(int i=1;i<=num;i++)
		{
			s+=t;
			o+=1;
		}
	}
	int l=0;
	long long r=o-1;
	long long num=0;
	while(l<r)
	{
		if(s[l]!=s[r])
		{
			s[r]=s[l];
			num++;
		}
		l++;
		r--;
	}
	cout<<num;
	return 0;
}