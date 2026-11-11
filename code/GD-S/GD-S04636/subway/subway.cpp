#include<bits/stdc++.h>
using namespace std;

const int N=1e6;

long long c,n,m,d,q;
struct site
{
	long long inx=0;
	int no[31];
	long long tt[31];
}qwq[N];

struct linea
{
	long long inx=0;
	int no[30000];
}awa[501];

long long boww[502][502];


long long w[N];

int main()
{
	cin.tie(0); 
	ios::sync_with_stdio(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++)
	{
		cin>>w[i];
		
	}
	
	for(long long i=0;i<n;i++)
	{
	long long tk;
	cin>>tk;
		for(long long j=0;j<tk;j++)
		{
		long long tp;
		cin>>tp;
		qwq[tp].no[qwq[tp].inx]=i;
		cin>>qwq[tp].tt[qwq[tp].inx];
		
		awa[i].no[awa[i].inx]=tp;
		
		awa[i].inx++;
		qwq[tp].inx++;
		}
	}
	
	for(long long i=0;i<m;i++)
	{
//		if(qwq[i].inx>1)
//		{
//cout<<"site "<<i<<" is:  ";
			for(long long j=0;j<qwq[i].inx;j++)
			{
				for(long long i2=0;i2<m;i2++)
				{
						for(long long k=0;k<qwq[i2].inx;k++)
						{
							if((boww[qwq[i].no[j]][qwq[i2].no[k]]==0)&&(qwq[i2].no[k]!=qwq[i].no[j]))
							{
								boww[qwq[i].no[j]][qwq[i2].no[k]]=qwq[i].tt[j]+qwq[i2].tt[k];	
								boww[qwq[i2].no[k]][qwq[i].no[j]]=qwq[i].tt[j]+qwq[i2].tt[k];				
							}
							boww[qwq[i].no[j]][qwq[i2].no[k]]=min(qwq[i].tt[j]+qwq[i2].tt[k] , boww[qwq[i].no[j]][qwq[i2].no[k]] );
							boww[qwq[i2].no[k]][qwq[i].no[j]]=min(qwq[i].tt[j]+qwq[i2].tt[k] , boww[qwq[i2].no[k]][qwq[i].no[j]] );
						}
						
				}
//			cout<<qwq[i].no[j]<<" "<<qwq[i].tt[j]<<" awa ";
			}
//			cout<<"\n";
//		}
	}
	
	
	
//		for(long long i=0;i<=m;i++)
//	{
//		for(long long j=0;j<=m;j++)
//	{
//	cout<<boww[i][j]<<" ";
//	}cout<<"\n";
//	}
	
	
	
	
	for(long long i=0;i<q;i++)
	{
		long long tt1,tt2,ans;
		cin>>tt1>>tt2;
		ans=w[tt1]+w[tt2];
		long long ts=0x3f3f3f3f3f3f3f3f;
		for(long long j=0;j<qwq[tt1].inx;j++)
		{
			
			for(long long k=0;k<qwq[tt2].inx;k++)
			{
//					cout<<"line "<<qwq[tt1].no[j]<<" to "<<"line "<<qwq[tt2].no[k]<<" use "<<boww[qwq[tt1].no[j]][qwq[tt2].no[k]]<<" "<<qwq[tt1].tt[j]<<" "<<qwq[tt2].tt[k]<<"\n";
					ts=min( qwq[tt1].tt[j]+qwq[tt2].tt[k] + boww[qwq[tt1].no[j]][qwq[tt2].no[k]],ts);
			}
		}
		cout<<ts+ans<<"\n";
//		cout<<greatfind(tt1,tt2)<<"\n";
	}
	
	
	return 0;
}
