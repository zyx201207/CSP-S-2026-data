#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct zt{
	long long bh;
	long long jl;
};
vector <long long> a[505];
zt b[505][505];
queue <long long> z;
long long gz[505],w[505],bj[505];
long long c,n,m,d,q,k,st,en;
bool yon[505];
void back()
{
	for(int i=0;i<505;i++)
	{
		bj[i]=999999999;
	}
	for(int i=0;i<505;i++)
	{
		yon[i]=0;
	}
}

void check()
{
	cout<<'\n'<<"check"<<'\n';
	for(int i=0;i<n;i++)
	{
		cout<<i<<'\n';
		for(int j=0;j<a[i].size();j++)cout<<a[i][j]<<' ';
		cout<<'\n';
	}
	for(int i=1;i<=m;i++)
	{
		cout<<i<<'\n';
		for(int j=0;j<n;j++)cout<<b[i][j].bh<<' '<<b[i][j].jl<<' ';
		cout<<'\n';
	}
	cout<<'\n'<<"ok"<<'\n';
}

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;	
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>k;
		for(int j=0;j<k;j++)
		{
			long long ls1,ls2;
			cin>>ls1>>ls2;
			zt ls4;
			ls4.bh=i;
			ls4.jl=ls2;
			a[i].push_back(ls1);
			b[ls1][i]=ls4;
		}
	}
	//check();
	for(int i=0;i<q;i++)
	{
		back(); 
		cin>>st>>en;
		bj[st]=w[st];
		z.push(st);
		yon[st]=1;
		while(!z.empty())
		{
			long long g=z.front();
			z.pop();
			for(int j=0;j<n;j++)
			{
				if(b[g][j].jl==0)continue;
				for(int j2=0;j2<a[j].size();j2++)
				{
					long long sjg=a[j][j2];
					if(sjg==g)continue;
					//cout<<bj[sjg]<<' '<<b[g][j].jl<<' '<<b[sjg][j].jl<<' '<<'\n';
					if(bj[sjg]>bj[g]+b[g][j].jl+b[sjg][j].jl)
					{
						bj[sjg]=bj[g]+b[g][j].jl+b[sjg][j].jl;
					}
					//cout<<bj[sjg]<<' '<<sjg<<'\n';
					if(yon[sjg]==0)
					{
						z.push(sjg);
						yon[sjg]=1;
					}
				}
			}
		}
		cout<<bj[en]+w[en]<<'\n';
	}
	return 0;	
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
