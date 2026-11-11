#include<bits/stdc++.h>
using namespace std;
const int N=1e8+10;
char c[N],x;
int n,a,i,j,ans=1,s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a>>x;
		for(j=ans;j<=ans+a-1;j++)
			c[j]=x;
		ans+=a;
	}
	s=ans;
	ans=0;
	for(i=1;i<=s/2;i++)
		if(c[i]!=c[s-i])
			ans++;
	cout<<ans;
	return 0;
}
