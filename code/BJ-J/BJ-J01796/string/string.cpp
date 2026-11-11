#include<bits/stdc++.h>
using namespace std;

int a[200005]={};
char c[200005]={};
long long ans=0;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int si=1;
	int ei=n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	int sl=a[1];
	int el=a[n];
	for(;;)
	{
		if(si>=ei)
		{
			break;
		}
		if(c[si]!=c[ei])
		{
			ans+=min(sl,el);
		}
		si++;
		ei--;
		if(sl>el)
		{
			si--;
			sl=(sl-el);
			el=a[ei];
		}
		if(sl<el)
		{
			ei++;
			el=(el-sl);
			sl=a[si];
		}
	}
	cout<<ans;
	return 0;
}
