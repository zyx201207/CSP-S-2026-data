#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
long long cnt;
char c;
string s;
int hws()
{
	long long l=0,r=s.size()-1;
	while(l<r)
	{
		if(s[l]!=s[r])
		{
			cnt++;
			//cout<<l<<" "<<r<<endl;
		}
		else if(l==r)
		{
			break;
		}
		l++,r--;
	}
	return cnt;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c;
		for(int j=1;j<=a[i];j++)
		{
			s+=c;
		}
	}
	cout<<hws();
	return 0;
}
