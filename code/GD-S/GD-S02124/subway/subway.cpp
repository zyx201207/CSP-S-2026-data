#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500005],k,fza[1005][3],la[1005][1005],zda[1005][1005],x,y,u,qul,qq,aa[1005][1005],bo[1005],qur;
long long qu[1000005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
		for(int j=1;j<=m;j++)
		{
			for(int k=1;k<=m;k++)
			{
				la[j][k]=2000000001;
			}
		}
		for(int i=1;i<=n;i++)
		{
			cin>>k;
			for(int j=1;j<=k;j++)
			{
				cin>>fza[j][1];
				cin>>fza[j][2];
			}
			for(int j=1;j<=k;j++)
			{
				for(int kk=1;kk<=k;kk++)
				{
					if(j==kk)
						continue;
					la[fza[j][1]][fza[kk][1]]=min(la[fza[j][1]][fza[kk][1]],fza[j][2]+fza[kk][2]);
				}
			}
		}
		for(int kk=1;kk<=m;kk++)
		{
			x=kk;
			qul=0;
			for(int i=1;i<=m;i++)
			{
				if(la[x][i]!=2000000001)
				{
					qu[++qul]=la[x][i]*1000+i;
				}
			}
			sort(qu+1,qu+qul+1);
			qq=x;
			qur=1;
			while(qur<=qul)
			{
				u=qu[qur];
				qur++;
				if(bo[u%1000]==1)
					continue;
				bo[u%1000]=1;
				aa[x][u%1000]=u/1000;
				u=u%1000;
				for(int i=1;i<=m;i++)
				{
					if(la[u][i]!=2000000001 and i!=qq)
					{
						qu[++qul]=(la[u][i]+aa[x][u])*1000+i;
					}
				}
				qq=u;
				if(qur<=qul)
					sort(qu+1+qur,qu+1+qul);
			}
			for(int i=1;i<=qul;i++)
				qu[i]=0;
			for(int i=1;i<=m;i++)
			{
				bo[i]=0;
			}
		}
		for(int kk=1;kk<=q;kk++)
		{
			cin>>x>>y;
			cout<<aa[x][y]+w[x]+w[y]<<endl;
		}
 } 
