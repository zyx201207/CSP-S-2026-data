#include<bits/stdc++.h>
using namespace std;
int n,a;
long long ans,sum;
char c;
string s;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>c,sum+=a;
		while(a--)
			s+=c;
	}
	for(int i=0;i<=ceil(sum/2.0)-1;i++)
		if(s[i]!=s[sum-i-1])
			ans++;
	cout<<ans;
	return 0;
}
