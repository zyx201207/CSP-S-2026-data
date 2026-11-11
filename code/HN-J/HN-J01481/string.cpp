#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,cnt=0;
	cin>>n;
	vector<long long>a(n);
	vector<string>b(n); 
	for(long long i=0;i<n;i++)
	{
		cin>>a[i]>>b[i];
	}
	string temp="",temp1="";
	for(long long i=0;i<n;i++)
	{
		for(int j=0;j<a[i];j++)
		{
			temp+=b[i];
			temp1+=b[i];
		}
	}
	reverse(temp.begin(),temp.end());
	for(long long i=0;i<temp.size();i++)
	{
		if(temp[i]!=temp1[i])
		{
			cnt++;
		}
	}
	cout<<cnt/2;
	return 0;
}
