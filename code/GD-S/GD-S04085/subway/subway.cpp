#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[1000005],a[100][1000005],t[100][1000005],k[1000005],rx[100005],ry[100005];
bool xbool,ybool; 
long long xx,yy;
int main() 
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(long long i=0;i<m;i++) cin>>w[i];
	for(long long i=0;i<n;i++)
	{
		cin>>k[i];
		for(int j=0;j<k[i];j++) cin>>a[i][j]>>t[i][j];
	}
	for(long long i=0;i<q;i++)
		cin>>rx[i]>>ry[i];
	for(long long s=0;s<q;s++)
	{
		for(long long i=0;i<n;i++)
		{
			xbool=false;
			ybool=false;
			for(long long j=0;j<k[i];i++)
			{
				if(a[i][j]==rx[s]) {xbool=true;xx=t[i][j];}
				if(a[i][j]==ry[s]) 
				{
					ybool=true;
					yy=w[i];
				}
			}
			if(xbool&&ybool) 
			{
				cout<<xx+yy;
			}
		}
	}
	return 0;
}









																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																					
