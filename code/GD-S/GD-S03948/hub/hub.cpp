#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int c,t;
long long n,k,cs[100005];
vector <long long> nb[100005];
bool bj[100005];
queue <long long> x;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	for(int i=0;i<t;i++)
	{
		cin>>n>>k;
		for(int i=0;i<n;i++)
		{
			nb[i].clear();
			cs[i]=0;
		}
		for(int j=1;j<n;j++)
		{
			long long x1,x2;
			cin>>x1>>x2;
			nb[x1].push_back(x2);
			nb[x2].push_back(x1);
		}
		x.push(1);
		bj[1]=1;
		while(!x.empty())
		{
			long long g=x.front();
			x.pop();
			for(int j=0;j<nb[g].size();j++)
			{
				if(!bj[nb[g][j]])
				{
					cs[nb[g][j]]=cs[g]+1;
					bj[nb[g][j]]=1;
					x.push(nb[g][j]);
				}
			}
		}
		for(int j=1;;j++)
		{
			long long all1=0,yb=1;
			for(int j2=0;j2<n;j2++)
			{
				if(cs[j2]==j || cs[j2]%(2*j)==j)all1++;
			}
			if(all1<=k)
			{
				cout<<all1<<' '<<j<<'\n';
				break;
			}
		}
	}
	return 0;
}
