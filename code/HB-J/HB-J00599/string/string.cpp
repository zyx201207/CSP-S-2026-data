#include <bits/stdc++.h>
using namespace std;
string s;
long long n,a;
char c;
long long ans;
int main()
{

	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		getchar();
		cin>>c;
	
		for(int j=1;j<=a;j++)
		{
			s+=c;
		}
	}
	long long l=0;
	long long r=s.size()-1;
	long long ll=s.size();

	for(long long  i=0;i<ll;i++)
	{
		if(l>=r)
		{
			
			break;
		}
		l=i;
		r=s.size()-i-1;
		if(s[l]!=s[r])
		{
			ans++;
			continue;
		}
		
	}
	cout<<ans;
	return 0;
}

