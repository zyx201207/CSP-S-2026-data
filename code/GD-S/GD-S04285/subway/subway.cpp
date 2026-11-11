#include<bits/stdc++.h>
using namespace std;
int n,m,c,d,q,k[505],x,y,a[5005][5005],t[5005][5005],l[505],s,l1[505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	long long w[m+1];
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			l[a[i][j]]=i,l1[a[i][j]]=j;
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>x>>y;
		s=0;
		s+=w[x]+w[y];
		int g=0;
		for(int j=l1[x];j<=k[l[x]];j++)
			if(a[l[x]][j]==y)g=1;
		if(g==0)
		for(int j=1;j<=k[x];j++)
		{
			s+=t[l[x]][j];
			if(l[a[l[x]][j]]==l[y])
			{
				x+=t[l[y]][l1[a[l[x]][j]]];
				for(int v=l1[a[l[x]][j]];;v++)
				{	
					s+=t[l[y]][v];
					if(a[l[a[l[x]][j]]][v]==y)break;
				}
				break;
			}
		}
		if(g==1){
			for(int j=l1[x];j<=k[l[x]];j++){
				s+=t[l[x]][j];
				if(a[l[x]][j]==y)break;
			}
		}
		cout<<s<<endl;
	}
	return 0;
}
