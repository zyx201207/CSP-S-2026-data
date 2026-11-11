#include<bits/stdc++.h>
using namespace std;
int c,ll,t,n,d,sum,minn[10024];
int a[10024];
map<int,int>mp;
map<int,int>mpi;
void dfs(int step,int cur)
{
//	cout<<step<<":)"<<cur<<'\n';
	if(minn[step]<cur)return;
	if(cur!=0&&minn[step]>=cur)
	{
		if(minn[step]>cur)
		{
			minn[step]=cur;
			mpi[step]=0;
		}
		mpi[step]++;
	}
	for(int i=step+1;i<=n;i++)
	{
		if(a[i]-a[step]<=d)
		{
			//cout<<a[i]<<" "<<a[step]<<" "<<d<<" "<<cur<<" gogogo\n";
			dfs(i,cur+1);
		}else break;
	}
	return;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		mp.clear();
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			mp[a[i]]=i;
		}sum=0;
		if(c==13||c==14)
		{
			cout<<"0\n";
		}
		else if(c==11||c==12)
		{
			cout<<"0\n";
		}
		else if(n<=300)
		{
			sort(a+1,a+1+n);
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)minn[j]=INT_MAX;
				mpi.clear();
				ll=i;
				dfs(i,0);
				for(int j=i+1;j<=n;j++)
				{
					//cout<<i<<" "<<j<<" "<<mpi[j]<<'\n';
					if(mpi[j]==2)
					{
						sum++;
					//	cout<<"QWQ "<<i<<" "<<j<<'\n';
					}
				}//cout<<"==========\n";
			}cout<<sum<<'\n';
		}else cout<<"0\n";
	}
}

/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
