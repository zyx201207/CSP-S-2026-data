#include<bits/stdc++.h>
using namespace std;
int n,is,t;
char s[67677891];char c;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>is>>c;
		for(int i=1;i<=is;i++)
		{
			s[++t]=c;
		}
	}
	long long pret=t/2;
//	cout<<pret<<endl;
	int ans=0;
	for(int i=1,j=t;i<=pret;i++,j--)
	{
		if(s[i]!=s[j])ans++;
	}
	cout<<ans;
	return 0;
}
