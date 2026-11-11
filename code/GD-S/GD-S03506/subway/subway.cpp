#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct node
{
	int step,time;
};
int c,n,m,d,q,start1,end1,start2,end2;
int w[5005],tee[505];
node many[505][505];
int time1,time2;
int num[100];
int over1;
int howmany[505];
int station_1[100],station_2[100];
int st1 =1,st2 =1;
int te1 = 1,temore = 100000;

int abc(int start,int end )
{
	over1+=w[start]+w[end];
	for(int i = 1;i<=n;i++)
	{
		for(int j = 1;j<=howmany[i];j++)
		{
			if(many[i][j].step == start)
			{
				station_1[st1] = i;
				st1++;
			}
			if(many[i][j].step == end)
			{
				station_2[st2] = i;
				st2++;
			}
		}
	}

    for (int i =1;i<st1;i++)
	{
		for(int j=1;j<=howmany[station_1[i]];j++)
		{
			for (int k =1;k<st2;k++)
			{
				for(int l=1;l<=howmany[station_2[k]];l++)
				{
					if(many[station_1[i]][j].step==many[station_2[k]][l].step)
					{	
						tee[te1] = many[station_1[i]][j].step;
						te1++;
						if(many[station_1[i]][j].time<=many[station_2[k]][l].time)
						{
							temore = min(many[station_1[i]][j].time,temore);
						}
						else
						{
							temore = min(many[station_2[k]][l].time,temore);
						}
					}
				}
			} 	
		}
			
	}
 
	over1+=temore;
	cout<<over1<<endl;
	return 0;
}

int main()
{
    //freopen("crystal.in","r",stdin);
    //freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>c>>n>>m>>d>>q;
    for(int i =1;i<=m;i++)
    {
		cin>>w[i];
	}


	for(int i = 1;i<=n;i++)
	{
		cin>>howmany[i];
		for(int j = 1;j<=howmany[i];j++)
		{
			cin>>many[i][j].step;
			cin>>many[i][j].time;
		}
	}
	cin>>start1>>end1;
	cin>>start2>>end2;
	abc(start1,end1);
	abc(start2,end2);
  	

	

	
 

}
