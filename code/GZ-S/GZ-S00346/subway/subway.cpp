//GZ-S00346 贵州省凯里市第一中学 何奕歆 
#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
struct sub
{
	int w,a[510],t[510];	
}s[510];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);	
	cin>>c>>n>>m>>d>>q;	
	for(int i=1;i<=m;i++)
	{
		cin>>s[i].w;
	}	
	int k;
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int aa,tt;
			cin>>aa>>tt;
			s[aa].a[i]=1;
			s[aa].t[i]=tt;
		}	
	}
	for(int i=1;i<=q;i++)
	{
		int time=0,xb=0;
		int x,y;cin>>x>>y;
		time+=s[x].w+s[y].w;
		for(int j=1;j<=n;j++)
		{
			if(s[x].a[j]){
				xb=j;break;
			}
		}
		if(s[y].a[xb])
			cout<<time+s[x].t[xb]+s[y].t[xb]<<endl;
		else
		{
			int tp=100001,xbb=0,yxb=0;
			for(int j=xb;j<=n;j++)
			{
				if(s[x].a[j]){
					xbb=j;break;
				}
			}
			for(int j=1;j<=n;j++)
			{
				if(s[y].a[j]){
					yxb=j;break;
				}
			}		
			for(int j=1;j<=m;j++)
			{
				if(s[j].a[xbb])
					tp=min(tp,s[j].t[xbb]);
			}
			cout<<time+s[x].t[xb]+s[y].t[xb]+2*tp+s[y].t[yxb]<<endl;
		}
	}
	
	return 0;
}

