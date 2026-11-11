#include<bits/stdc++.h>
using namespace std;
int n;
long long a;
char c;
string s="";
int i,j;
long long ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for ( int i=1; i<=n; i++ )
	{
		scanf ( "%lld %c",&a,&c );
		while ( a-- ) s+=c;
	}
	i=0,j=s.size()-1;
	while ( i<=j )
	{
		if ( s[i]!=s[j] )
		{
			ans++;
		}
		i++,j--;
	}
	cout<<ans;
	return 0;
}
