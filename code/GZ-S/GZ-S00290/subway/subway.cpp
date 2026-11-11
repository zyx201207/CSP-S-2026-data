#include<bits/stdc++.h>//贵阳市花溪区剑桥中学  李政轩   GZ-S00290
using namespace std;
const int maxn = 1e6+325;
long long c,m,n,p,d,k,sum;
//分别表示测试点编号c、地铁线路数n、地铁站数m、每个地铁站最多被几条线路经过d，以及出行计划数q
long long w[maxn];
struct sub{
	long long t;
	long long l;
}a[maxn];
struct plan{
	long long e;
	long long start;
}b[maxn];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>p;
	for(int i = 1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i = 1;i<=n;i++)
	{
		cin>>k;
		for(int j = 1;j<=k;j++)
		{
			cin>>a[j].l>>a[j].t;
		}
	}
	for(int i = 1;i<=p;i++)
	{
		cin>>b[i].start>>b[i].e;
		sum+=w[b[i].start]+w[b[i].e]+a[b[i].start].t+a[b[i].e].t;
        cout<<sum<<endl;
        sum = 0;
	}
	return 0;
}
