#include<bits/stdc++.h>
using namespace std;
long long n,a,sum=0;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	char c;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>c;
		while(a--)
		s+=c;
	} 
	long long i=0,j=s.size()-1;
	while(i<j)
	{
		if(s[i]!=s[j])sum++;
		i++;
		j--;
	}
	cout<<sum;
	return 0;
 } 
