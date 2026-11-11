//GZ-S00281 遵义航天高级中学 罗上 
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
int c,n,m,d,q;
int w[500005];
int to[20];
unsigned int time[20];
int main()
{
	ifstream in("subway.in",ios::in);
	ofstream out("subway.out",ios::out);
	in>>c>>n>>m>>d>>q;
	vector<vector<unsigned int> > tu(m+1,vector<unsigned int>(m+1,2147483647));
	for(int i=1;i<=m;i++)
	{
		tu[i][i]=0;
		in>>w[i];
	}
	int k;
	for(int i=0;i<n;i++)
	{
		in>>k;
		for(int j=0;j<k;j++)
		{
			in>>to[j]>>time[j];
			for(int x=j-1;x>=0;x--)
			{
				tu[to[j]][to[x]]=min(tu[to[j]][to[x]],time[j]+time[x]);
				tu[to[x]][to[j]]=tu[to[j]][to[x]];
			}
		}
	}
	for(int k=1;k<=m;k++)
	{
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=m;j++)
			{
				tu[i][j]=min(tu[i][j],tu[i][k]+tu[k][j]);
			}			 
		}
	}
	int x,y;
	for(int i=0;i<q;i++)
	{
		in>>x>>y;
		out<<tu[x][y]+w[x]+w[y]<<'\n';
	}
	in.close();
	out.close();
	return 0;
}

