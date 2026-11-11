#include <bits/stdc++.h>
using namespace std;
const int N=1e8+5;
int s[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long start=0;
	for(int i=0;i<n;i++)
	{
		long long int num;
		char c;
		cin>>num>>c;
		for(long long int j=0;j<num;j++)
		{
			s[start]=c-'0';
			start++;
		}
	}
	long long ans=0;
	for(long long int i=0;i<start/2;i++)
	{
		if(s[i]!=s[start-i-1]) ans++;
	}
	cout<<ans<<endl;
	return 0;
}

