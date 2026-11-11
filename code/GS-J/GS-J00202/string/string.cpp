#include<bits/stdc++.h>

using namespace std;

long long n,cc,a,len=1,mid,mx,l,r;
string s[200005],b;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>b;
		for(int j=len;j<len+a;j++)
		{
			s[j]=b;
		}
		len+=a;
	}
	//for(int i=1;i<=len;i++)
	//{
	//	cout<<s[i];
	//}
	mid=(len+1)/2;
	l=1;
	r=len-1;
	for(int i=1;i<mid;i++)
	{
		if(s[l]!=s[r])
		{
			cc++;
		}
		l++;
		r--;
	}
	cout<<cc;
	return 0;
}
