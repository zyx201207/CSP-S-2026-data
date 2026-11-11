#include<bits/stdc++.h>
using namespace std;
int n,numb[200005];
char a;
long long cnt=0,ans=0;
string n1;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>numb[i]>>a;
		for(int j=1;j<=numb[i];j++)
		{
			n1+=a;
		}
	}
	cnt=n1.size();
	for(int i=0;i<cnt/2;i++)
	{
		if(n1[i]!=n1[cnt-i-1])
		{
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
