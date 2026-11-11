#include<bits/stdc++.h>
using namespace std;
string s2;
char s[200005];
long long a[200005],n,ans,l1,l2,sum,str[200005],z;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>s[i];
		sum+=a[i];
		str[i]=str[i-1]+a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=a[i];j++)
		s2+=s[i];
	}
	l1=s2.size();
	l2=l1/2;
	for(int i=0;i<l2;i++)
	{
		if(s2[i]!=s2[l1-i-1])
		ans++;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
