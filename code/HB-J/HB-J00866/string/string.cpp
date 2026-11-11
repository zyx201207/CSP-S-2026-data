#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;long long cnt=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].ll>>a[i].c;
		cnt+=a[i].ll;
	}
	
	for(int i=1;i<=n;i++)
	{
		b[a[i].c-'a']+=a[i].ll;
	}
	sort(b,b+26);
	if(b[25]!=cnt)
	{
		if(b[25]>cnt/2) cout<<cnt-b[25];
		else cout<<cnt/2;
	}
	else cout<<0;
	return 0;
}
