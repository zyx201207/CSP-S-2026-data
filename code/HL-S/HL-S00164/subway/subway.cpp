#include<bits/stdc++.h>
using namespace std;
const int maxn=10000000;
const int maf=0x3f3f3f3f;
int w[maxn];
int t[maxn];
int num[maxn];
int dist[maxn];
bool sign[maxn];
int line[10000][10000];
int linen,stan,d,r;

void build(int pstan)
{
	for(int i=1;i<=pstan;i++)
	{
		for(int j=i+1;j<=pstan;j++)
		{
			line[num[i]][num[j]]=t[i]+t[j];
			line[num[j]][num[i]]=t[i]+t[j];
		}
	}
}
int dj(int s,int e)
{
	for(int i=0;i<=stan;i++)
	{
		dist[i]=maf;
		sign[i]=0;
	}
	dist[s]=0;
	for(int round=1;round<=stan;round++)
	{

		int u=0;
		for(int i=1;i<=stan;i++)
		{
			if(!sign[i]&&dist[i]<dist[u])
			{
				u=i;
			}
		}
//		cout<<u<<endl;
		if(dist[u]==maf) break;
		if(u==e) return dist[u];
		sign[u]=1;
		for(int v=1;v<=stan;v++)
		{
			if(line[u][v])
			{
			
				if(!sign[v]&&dist[v]>dist[u]+line[u][v])
				{
					dist[v]=dist[u]+line[u][v];
				}
		    }
		}
	}
	return -1;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	int c;
	cin>>c;
	cin>>linen>>stan>>d>>r;
	for(int i=1;i<=stan;i++)
	{
		cin>>w[i];
	}
	int pstan; 
	for(int i=1;i<=linen;i++)
	{
		cin>>pstan;
		for(int i=1;i<=pstan;i++)
		{
			cin>>num[i]>>t[i];
		}
		build(pstan);
	}
	int x,y;
	for(int i=1;i<=r;i++)
	{
		cin>>x>>y;
		cout<<dj(x,y)+w[x]+w[y]<<endl; 
	 } 
	
} 



