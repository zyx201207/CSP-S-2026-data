#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	if(c==0)
	{
		
	}
	int w[500000];
	int a[500][500];
	int t[500][500];
	int s[10000],e[10000];
	for(int i=0;i<m;i++)
	{
		cin>>w[i];
	}
	int k;
	for(int i=0;i<n;i++)
	{
		cin>>k;
		for(int j=0;j<k;j++)
		{
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=0;i<q;i++)
	{
		cin>>s[i]>>e[i];
		
	}
	int l=0,o=0;
	for(int k=0;k<q;k++)
	{
		o=0; l=0;
	for(int i=0;i<n;i++)
	{
		
		for(int j=0;j<n;j++)
		{
			if(a[i][j]==s[k]) l=j;
			if(a[i][j]==e[k]) o=j;
		}
		
	if(l!=0&&o!=0)
	{
		cout<<w[s[k]]+w[e[k]]+t[i][l]+t[i][o];
	}
	}
}
	return 0;
}
