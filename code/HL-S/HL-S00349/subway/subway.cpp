#include<bits/stdc++.h>
using namespace std;
const int N=1000010;
long long n,m,num,k,c,d,q;
long long a[10010][10010],t[10010][10010];
long long w[N],s[N],ti[N];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>a[i][j]>>t[i][j];
			
		}
		s[a[i][1]]=a[i][2];
		s[a[i][2]]=a[i][1];
		ti[a[i][1]]=t[i][1]+t[i][2];
		ti[a[i][2]]=t[i][1]+t[i][2];
		
	}
	int x,y;
	while(q--)
	{
		cin>>x>>y;
		cout<<x<<' '<<y<<endl;
		num=w[x]+w[y];
		while(x!=y)
		{
			num+=ti[x];
			x=s[x];
		}
		cout<<num<<endl;
		num=0;
		x=0;y=0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
