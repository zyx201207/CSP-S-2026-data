//GZ-J00019 µËÔÆÐù
#include<bits/stdc++.h>
using namespace std;
int n;
string s,sc;
char c;
long long a[200005],len,ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		cin >> c;
		len+=a[i];
		for(int j=1;j<=a[i];j++)
		{
			s+=c;
		} 
	}
	sc=s;
	for(long long i=0;i<len/2+1;i++)
	{
		swap(s[i],s[len-i-1]);
	}
	if(s==sc)
	{
		cout << "0";
		return 0;
	}
	s=sc;
	for(long long i=0;i<len;i++)
	{
		for(long long j=len-1;j>=0;j--)
		{
			if(s[i]!=s[j])
			{
				s[j]=s[i];
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}
