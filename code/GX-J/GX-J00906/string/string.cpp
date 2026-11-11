#include<bits/stdc++.h>
using namespace std;
vector<char> a;
int n,ans,cnt;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1,nb;i<=n;i++)
	{
		char ch;
		cin>>nb>>ch;
		ans+=nb;
		for(int j=1;j<=nb;j++)
		{
			a.push_back(ch);
		}
	}
	for(int i=0;i<=ans/2;i++)
	{
		if(a[i]!=a[ans-i-1])
		{
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
