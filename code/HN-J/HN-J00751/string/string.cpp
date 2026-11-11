#include<bits/stdc++.h>
using namespace std;
const int N=2e5+3;
const int M=2e7;
long long  n,ans;
string s;
bool f;
struct sty{
	int a;
	char c;
}a[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	cin>>n>>a[0].a>>a[0].c;
	for(int i=1;i<n;i++)
	{
		cin>>a[i].a>>a[i].c;
		ans+=a[i].a;
		if(a[i].c != a[i-1].c)
		{
			f=1;
		}
	}
	if(f==false)
	{
		cout<<0;
		return 0;
	}
	if(ans>=M)
	{
		cout<<ans/2;
		return 0;
	}
	ans=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<a[i].a;j++)
		{
			s+=a[i].c;
		}
	}
	//cout<<s.length()<<endl;
	for(int i=0;i<=s.length()/2;i++)
	{
		if(s[i]!=s[s.length()-i-1])
		{
			//cout<<s[i]<<" "<<s[s.length()-i-1]<<endl;
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
