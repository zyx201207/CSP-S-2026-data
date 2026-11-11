//GZ-J00005 福泉中学 向治衡 
#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long n,sz=0,num=0;
	cin>>n;
	vector<char>s(n);
	for(int i=0;i<n;i++)
	{
		long long a;
		char c;
		cin>>a>>c;
		for(int j=sz;j<sz+a;j++)
		{
			s[j]=c;
		}
		sz+=a;
	}
	for(int i=0,j=sz-1;i<j;i++,j--)
	{
		if(s[i]!=s[j])
		{
			num++;
		}
	}
	cout<<num;
	return 0;
}
