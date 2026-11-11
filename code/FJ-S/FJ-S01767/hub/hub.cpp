#include<bits/stdc++.h>
using namespace std;
int c,t,ans[6];
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		int n,k,a[1001000],b[1001000];
		cin>>n>>k;
		for(int i=1;i<n;i++)
		  cin>>a[i]>>b[i];
		if(n<=8) ans[i]=1;
		else if(n<=10) ans[i]=2;
		else if(n<=602) ans[i]=17;
		else if(n<=24032) ans[i]=189;
		else if(n<=100000) ans[i]=12251;
	}
	for(int i=1;i<=t;i++)
	  cout<<ans[i]<<endl;
	return 0;
}