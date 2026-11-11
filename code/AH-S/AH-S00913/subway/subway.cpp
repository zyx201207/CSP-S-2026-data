#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int Maxn=505;
const int Maxm=5e5+5;
const int Maxq=1e5+5;
ll a[Maxm];
vector<pair<int,ll> > sta[Maxn];
vector<pair<int,ll> > line[Maxm];
vector<pair<int,int> > ques[Maxn];
ll ans[Maxq];
bitset<Maxm> can_go[Maxn];
ll tu[Maxn][Maxn];
ll dist[Maxn][Maxn];
struct FastScanner
{
	static const int SZ=1<<20;
	int idx=0, size=0;
	char buf[SZ];
	inline char readChar()
	{
		if(idx>=size)
		{
			size=(int)fread(buf,1,SZ,stdin);
			idx=0;
			if(size==0) return 0;
		}
		return buf[idx++];
	}
	template <class T> bool readInt(T &out)
	{
		char c=readChar();
		if(!c) return false;
		while(c!='-' && (c<'0' || c>'9'))
		{
			c=readChar();
			if(!c) return false;
		}
		T sign=1;
		if(c=='-')
		{
			sign=-1;
			c=readChar();
		}
		T num=0;
		while(c>='0' && c<='9')
		{
			num=num*10+(c-'0');
			c=readChar();
		}
		out=sign*num;
		return true;
	}
}fs;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c, n, m, d, q;
	fs.readInt(c);
	fs.readInt(n);
	fs.readInt(m);
	fs.readInt(d);
	fs.readInt(q);
	for(int i=0;i<m;i++)
	{
		fs.readInt(a[i]);
	}

	memset(tu,0x3f,sizeof(tu));
	for(int i=1;i<=n;i++)
	{
		tu[i][i]=0;
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		fs.readInt(k);
		for(int j=0;j<k;j++)
		{
			int x;
			ll t;
			fs.readInt(x);
			fs.readInt(t);
			x--;
			sta[i].push_back({x,t});
			line[x].push_back({i,t});
		}
		// cout << "\n";
		// for(int j=1;j<=m;j++)
		// {
		// 	cout << can_go[i][j] << " ";
		// }
		// cout << "\n";
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<line[i].size();j++)
		{
			for(int k=j+1;k<line[i].size();k++)
			{
				tu[line[i][j].first][line[i][k].first]=min(tu[line[i][j].first][line[i][k].first],line[i][j].second+line[i][k].second);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int k=1;k<=n;k++)
		{
			for(int j=i+1;j<=n;j++)
			{
				tu[i][j]=min(tu[i][j],tu[i][k]+tu[k][j]);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<i;j++)
		{
			tu[i][j]=tu[j][i];
		}
	}
	// for(int i=1;i<=n;i++)
	// {
	// 	for(int j=1;j<=n;j++)
	// 	{
	// 		cout << tu[i][j] << " ";
	// 	}
	// 	cout << "\n";
	// }
	for(int i=1;i<=q;i++)
	{
		int x, y;
		fs.readInt(x);
		fs.readInt(y);
		x--, y--;
		ll ans=0x3f3f3f3f3f3f3f3f;
		for(int st=0;st<line[x].size();st++)
		{
			for(int ed=0;ed<line[y].size();ed++)
			{
				ans=min(ans,line[x][st].second+line[y][ed].second+tu[line[x][st].first][line[y][ed].first]);
			}
		}
		printf("%lld\n",ans+a[x]+a[y]);
	}
	return 0;
}