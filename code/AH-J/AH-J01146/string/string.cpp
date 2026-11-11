#include<bits/stdc++.h>
using namespace std;
long long a[100010];
char c[100010];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long l=0;
	string s="";
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		string t(a[i],c[i]);
	//cout<<t;
		l=l+a[i];
		s=s+t;
	}
	//cout<<s;
	long long ans=0;
	for(long long i=0;i<l/2;i++)
	{
	//	cout<<s[i]<<' '<<s[l-i+1]<<endl;
		if(s[i]!=s[l-i-1])
		{

			ans++;
		}
	}
	cout<<ans;
	return 0;
}
