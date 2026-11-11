#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200005],sum=0,lenf=0;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		char x;
		cin>>a[i]>>x;
		for(long long j=0;j<a[i];j++)
			s+=x;
	}
	lenf=s.size();
	for(long long i=0;i*2<=lenf;i++)
		if(s[i]!=s[lenf-i-1])
			sum++;
	cout<<sum;
	return 0;
}
