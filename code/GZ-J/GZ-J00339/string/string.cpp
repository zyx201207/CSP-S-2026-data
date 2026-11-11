//GZ-J00339 贵阳市南明区华麟学校 孙君瑞
#include<bits/stdc++.h>
using namespace std;
int n,a[200005],cnt;
char s[200005];
string c;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>s[i];
		for(int j=1;j<=a[i];j++)
		{
			c+=s[i];
		}
	}
	int len=c.size();
	for(int i=0,j=len-1;i<=(len-1)/2;i++,j--)
	{
		if(c[i]!=c[j])
		{
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
