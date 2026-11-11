#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n;
string s;
int ans;
struct node
{
	int a;
	char w;
};
node o[N];
bool hw()
{
	for(int i=1;i<=n/2;i++)
	{
		if(s[i]!=s[n-i+1])
			return false;
	}
	return true;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	s+=' ';
	for(int i=1;i<=n;i++)
	{
		cin>>o[i].a>>o[i].w;
		for(int j=1;j<=o[i].a;j++)
		{
			s+=o[i].w;
		}
	}
	n=s.size()-1;
	if(hw())
	{
		cout<<'0'<<endl;
		return 0;
	}
	for(int i=1;i<=n/2;i++)
	{
		int j=n-i+1;
		if(s[i]!=s[j])
		{
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
