#include <bits/stdc++.h>
using namespace std;
int f[1000005];
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int n,m;
	cin>>n>>m;
	f[0]=1;
	f[1]=n+1;
	for(int i=2;i<=m+1;i++)
	{
		f[i]=(f[i-1]+1)*f[i-1];
		cout<<f[i]<<endl;
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
