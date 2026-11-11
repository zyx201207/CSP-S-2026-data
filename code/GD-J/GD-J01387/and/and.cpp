#include<bits/stdc++.h>
using namespace std;
int n,m;
const int MAXN=2e5+10;
long a[MAXN];
long ans;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		ans=max(ans,a[i]);
	}
	if(m==1)
	{
		cout<<ans;
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
