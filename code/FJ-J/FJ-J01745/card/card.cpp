#include<bits/stdc++.h>
using namespace std;
int a[500101],b[500101],f[300101],c[500101],ct=0,d[300101];
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i1=1;i1<=n;i1++)
		cin>>a[i1];
	for(int i1=n;i1>0;i1--)
	{
		if(f[a[i1]])
			b[i1]=1,b[f[a[i1]]]+=2;
		f[a[i1]]=i1;
	}
	for(int i1=1;i1<=m;i1++)
		f[i1]=0;
	for(int i1=1;i1<=n;i1++)
	{
		if(b[i1]==2)
			f[a[i1]]=0;
		while(ct&&!f[a[c[ct]]])
			ct--;
		if(!ct)
			d[a[i1]]=max(d[a[i1]],i1);
		else
			d[a[i1]]=max(d[a[i1]],i1-c[ct]);
		if(b[i1]==1||b[i1]==3)
			c[++ct]=i1,f[a[i1]]=1;
	}
	for(int i1=1;i1<=m;i1++)
		cout<<d[i1]<<' ';
	return 0;
}
