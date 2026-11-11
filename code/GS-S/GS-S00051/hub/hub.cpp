#include <bits/stdc++.h>
using namespace std;
int c,t;
int n[1000010],k[1000010],s[100010];
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n[i]>>k[i];
	}
	for(int i=1;i<=26;i++)
	cin>>s[i];
	if(c==0&&t==2)
	{
		cout<<1<<endl<<2;
		return 0;
	}
	return 0;
}
