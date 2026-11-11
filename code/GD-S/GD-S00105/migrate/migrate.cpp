#include <bits/stdc++.h>
using namespace std;
long long n,df,x,min_step[1000005];
//vector<long long> dis;
queue<long long> lst;
/*long long distent(long long x,long long y)
{
	return dis[y+1]-dis[x];
}*/
/*long long DFS(long long now,long long times)
{
	long long p=0,to=n;
	while (df>=dis[to]-dis[now]) to--;
	if (to<=now) return 0;
	for (;to>now;to--)
	{
		if (times>min_step[to]) break;
		else if(times==min_step[to])
		{
			p++;
			//cout<<"?^"<<now<<" "<<to<<" "<<times<<endl;
		}
		else min_step[to]=times,p++;
		p+=DFS(to,times+1);
	}
	return p;
}*/
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t;
	cin>>c>>t;
	for (int k=1;k<=t;k++)
	{
		vector<long long> island;
		//dis.clear();
		cin>>n>>df;
		cin>>x;
		island.push_back(x);//先输入一次 
		//dis.push_back(0);
		for (int i=1;i<n;i++)
		{
			cin>>x;
			island.push_back(x);
		}
		//for (int i=1;i<n;i++) cout<<dis[i]<<"-";
		//cout<<":"<<endl;
		if (c==11||c==12) 
		{
			long long pls=df/island[2]-island[1];
			if (df<2) cout<<0<<endl;
			else
			{
				long long add=1,sum=0;
				for (int i=4;i<=n;i++)
				{
					sum+=add;
					if (i%pls!=0) add++;
				}
				cout<<sum<<endl;
			} 
		}
		else
		{
			long long sum=0;
			memset(min_step,-1,sizeof(min_step));
			min_step[1]=0;
			for (int i=1;i<n;i++)
			{
				//cout<<":"<<min_step[1];
				//sum+=DFS(i,1);
				/*cout<<":";
				for (int j=1;j<=n;j++) cout<<min_step[i]<<" ";
				cout<<endl;*/
				for (int j=n;j>i;j--)
				{
					//cout<<" dis:"<<island[j]-island[i];
					if (island[j]-island[i]<=df)
					{
						if (min_step[j]==min_step[i]+1) sum++;
						else if (min_step[j]==-1) min_step[j]=min_step[i]+1;
					}
				}
			}
			cout<<sum<<endl;
		}
	}
}
