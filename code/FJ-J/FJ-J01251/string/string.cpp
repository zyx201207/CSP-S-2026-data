#include <bits/stdc++.h>
using namespace std;

int n;
string s;
long long ans;
long long sum;


int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin>>n;
	
	
	for(int i=0;i<n;++i)
	{
		long long a;
		char c;
		cin>>a>>c;
		
		for(int j=0;j<a;++j)
			s+=c;

		sum+=a; 
	}
	
	
	for(int i=0;i<sum/2;++i)
	{
		if(s[i]!=s[sum-i-1])
			ans++;
	}
	

	cout<<ans<<'\n';
	return 0;	
} 
