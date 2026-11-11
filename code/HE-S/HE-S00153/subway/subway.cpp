#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,ans;
long long w[500005];
long long a;
long long t;
int f[500005]; 
struct bian{
	int zuo,you;
	long long quan;
}b[500005];
int find(int now)
{
	if(now==f[now])
	{
		return now;
	}
	else
	{
		return f[now]=find(f[now]);
	}
}
void join(int zuo,int you,int bl)
{
	int zz=find(zuo);
	int yy=find(you);
	ans+=b[bl].quan;
	ans=0; 
	f[yy]=zz;
}
bool pan(bian x,bian y)
{
	return x.quan<y.quan;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	//看到第二题 
	//直接一个并查集 
	//结果很纳尼 
	//
	//
	//
	//
	//
	//
	//
	//
	//
	//
	//
	//
	//
	//
	//
	//
	//
	//
	//
	//
	//
	//
	//
	//
	//
	//
	//
	//
	//
	//
	//
	//
	//
	//
	//
	//
	//
	//
	//
	//
	//
	//
	//
	//
	//
	//
	//
	//
	//
	//
	//
	//纳尼？ 
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
		f[i]=i;
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>a>>t;
		}
	}
	sort(b+1,b+1+n,pan);
	while(q--)
	{
		int xr,yr;
		cin>>xr>>yr;
		cout<<w[xr]+w[yr]+ans<<'\n';
	}
	
	//cout<<"没文件";
	//Oct31==Dec25?
	return 0;
}

