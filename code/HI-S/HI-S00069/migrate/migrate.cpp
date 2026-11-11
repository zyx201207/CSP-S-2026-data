#include <bits/stdc++.h>
using namespace std;
int a[500010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n,m,flag=0;
	cin>>c>>t;
	while(t--)
	{
		memset(a,0,sizeof(a));
		cin>>n>>m;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			if(i!=0&&a[i]-a[i-1]<m)flag=1;
		}
		int r=a[1]-a[0];
		if(flag==0)cout<<0<<'\n';
		else if(r*2<=m)cout<<max(0,n-m/r)<<'\n';
		else cout<<0<<'\n';
	}
	return 0;
}
