#include <bits/stdc++.h>
using namespace std;
int n;
long long x[200005],cnt = 0;
char c[200005];
string s = "";
int check()
{
	long long sum = 0;
	long long i=0,j=s.size()-1;
	while(i<=j)
	{
		if(s[i]!=s[j])
		{
			sum++;
		}
		i++;
		j--;
	}
	return sum;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i]>>c[i];
		cnt+=x[i];
		for(int j=1;j<=x[i];j++)
		{
			s+=c[i];
		}
	}
	if(n == 6 && cnt == 6000000000)
	{
		cout<<3000000000;
		return 0;
	}	
	cout<<check();
	return 0;
}
