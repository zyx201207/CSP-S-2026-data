#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n,sum=0; cin>>n;
	string t="";
	vector<int> a(n+1);
	vector<char> b(n+1);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		sum+=a[i];
		for(int j=1;j<=a[i];j++) t+=b[i];
	}
	int cnt=n/2,ans=0;
	for(int i=1,j=n;i<=cnt or j>=cnt+1;i++,j--)
	{
		if(b[i]!=b[j]) ans+=max(a[i],a[j]);
		else if(b[i]==b[j])
		{
			if(a[i]==a[j]) continue;
			else
			{
				if(i==cnt and j==cnt+1) {}
				else ans+=max(a[i],a[j]);
			}
		}
	}
	cout<<ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
