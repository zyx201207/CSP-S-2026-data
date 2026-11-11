#include<bits/stdc++.h>
using namespace std;
int czsj[500123];
long long cd[510][510];
vector<pair<int,int> > xl[500123];
vector<pair<int,int> > zd[510];
void read(int& a)
{
	a=0;
	char c=getchar();
	while(c!=' '&&c!='\n'&&c!=EOF)
	{
		a=a*10+c-48;
		c=getchar();
	}
}
int main()
{
	//*
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	//*/
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n,m,d,Q;
	read(n);read(n);read(m);read(d);read(Q);
	for(int q=1;q<=m;++q) read(czsj[q]);
	for(int q=1;q<=n;++q)
	{
		int k;
		read(k);
		for(int w=0;w<k;++w)
		{
			int szd,t;
			read(szd);
			read(t);
			zd[q].push_back({szd,t});
			xl[szd].push_back({q,t});
		}
	}
	for(int q=1;q<=n;++q)
	{
		for(int w=1;w<=n;++w) cd[q][w]=9e18;
	}
	for(int q=1;q<=n;++q)//xl
	{
		for(pair<int,int> w:zd[q])//xl->zd
		{
			for(pair<int,int> e:xl[w.first])//xl->zd->xl
			{
				cd[q][e.first]=min(cd[q][e.first],(long long)w.second+e.second);
			}
		}
		cd[q][q]=0;
	}
	for(int q=1;q<=n;++q)
	{
		for(int w=1;w<=n;++w)
		{
			for(int e=1;e<=n;++e)
			{
				cd[q][w]=min(cd[q][w],cd[q][e]+cd[e][w]);
			}
		}
	}
	while(Q--)
	{
		int x,y;
		long long ans=9e18;
		read(x);
		read(y);
		for(int q=0;q<xl[x].size();++q)
		{
			for(int w=0;w<xl[y].size();++w)
			{
				ans=min(ans,cd[xl[x][q].first][xl[y][w].first]+xl[x][q].second+xl[y][w].second);
			}
		}
		cout<<ans+czsj[x]+czsj[y]<<'\n';
	}
	return 0;
}
//压缩? 
//a线路到b线路? 
//awa 孺子可教也 
//我已开智 
//!?floyd?!
//!?long long?!

//唉 最高复杂度:4*1e9 
//我是法国赌神皮尔克松 我赌评测机性能够好 

//now-> 15:40


/*
freopen("subway.in","r",stdin);
freopen("subway.out","w",stdout);
freopen("subway.in","r",stdin);
freopen("subway.out","w",stdout);
//freopen("subway.in","r",stdin);
//freopen("subway.out","w",stdout);
//freopen("subway.in","r",stdin);
//freopen("subway.out","w",stdout);
me want up mi huo xing wei da shang
so i love CCF
wow i love CCF
i wu yi am happy
but my fenshu is not gao
me wu yi shi fen nu de
beacouse i'm not hui xie

and me am the CQ-J00278
*/
