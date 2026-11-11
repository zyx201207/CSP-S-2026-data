#include<bits/stdc++.h>
using namespace std;
int x[500001]={0},n=0,m=0;
bool mn[300001]={true};
void fast_io()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}
struct q
{
	int ans=0;
	bool answer=false;
}b[300001];
struct s
{
	int nm=0;//ÅÆ 
	int num=0;//ÅÆ×À 
}a[500001];
void g(int y,int id)
{
	if(y>n)
	{
		return;
	}
	for(int i=y;i<=n;++i)
	{
		if(mn[a[i].nm])
		{
			int idx=id;
			id=x[a[i].nm];
			for(int j=x[a[i].nm];j<idx;++j)
			{
				mn[a[j].num]=false;
				x[a[j].num]=0;
				a[j].num=0;
			}
			a[id].num=a[i].nm;
			mn[a[i].nm]=true;
			x[a[i].nm]=id;
			id++;
		}
		else
		{
			a[id].num=a[i].nm;
			mn[a[i].nm]=true;
			x[a[i].nm]=id;
			id++;
		}
	}
	for(int i=y;i<id;++i)
	{
		b[a[i].num].ans++;
		mn[a[i].num]=false;
		x[a[i].num]=0;
	}
	g(y+1,y+1);
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i].nm;
		mn[a[i].nm]=false;
		b[a[i].nm].answer=true;
	}
	g(1,1);
	for(int i=1;i<=n;++i)
	{
		if(b[i].answer)
		{
			cout<<b[i].ans<<" ";
		}
	}
	return 0;
}
