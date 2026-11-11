#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
typedef long long ll;
inline int kd()
{
	char ca=getchar();
	bool fffff=true;
	int res=0;
	while(ca<'0'||ca>'9')
	{
		if(ca=='-') fffff=false;
		ca=getchar();
	}
	while(ca>='0'&&ca<='9') res=(res<<1)+(res<<3)+('0'^ca),ca=getchar();
	return (fffff?res:-res);
}
int _,q,n,m,d,len;
struct query{
	int ss;
	int tt;
	ll ans;
	int siz;
}qr[N];
ll w[N],stl[N];
struct Node{
	int dian;
	int zhi;
	Node(int u,int zhii):dian(u),zhi(zhii) {}
	bool operator>(const Node& a) const {
		return zhi>a.zhi;
	}
};
struct edge{
	int nxt;
	int to;
	ll zhi;
}e[1000005];
int head[N],a[N],b[N];
priority_queue<Node,vector<Node>,greater<Node> > qu;
void add(int tu,int tv,int ts)
{
	e[++len].to=tv;
	e[len].zhi=ts;
	e[len].nxt=head[tu];
	head[tu]=len;
}
bool cmp(query x,query y)
{
	return x.ss<y.ss;
}
bool cmp1(query x,query y)
{
	return x.siz<y.siz;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>_>>m>>n>>d>>q;
	for(int i=1;i<=n;i++) cin>>w[i];
	for(int i=1;i<=m;i++)
	{
		int t;
		cin>>t;
		for(int j=1;j<=t;j++) cin>>a[j]>>b[j];
		for(int j=1;j<=t;j++) for(int k=1;k<=t;k++) if(j!=k) add(a[j],a[k],b[j]+b[k]);
	}
	for(int i=1;i<=q;i++) cin>>qr[i].ss>>qr[i].tt,qr[i].siz=i;
	sort(qr+1,qr+q+1,cmp);
	for(int s=1,j=1;s<=n;s++)
	{
		memset(stl,127,sizeof(stl));
		if(qr[j].ss!=s) continue;
		stl[s]=0;
		bool vis[N]={0};
		qu.push(Node(s,0));
		while(!qu.empty())
		{
			Node no=qu.top();
			qu.pop();
			if(vis[no.dian]) continue;
			vis[no.dian]=1;
			for(int i=head[no.dian];i;i=e[i].nxt)
			{
				int ne=e[i].to;
				if(stl[ne]>stl[no.dian]+e[i].zhi)
				{
					stl[ne]=stl[no.dian]+e[i].zhi;
					qu.push(Node(ne,stl[ne]));
				}
			}
		}
		while(j<=q&&qr[j].ss==s) qr[j].ans=stl[qr[j].tt]+w[s]+w[qr[j].tt],j++;
		if(j>q) break;
	}
	sort(qr+1,qr+q+1,cmp1);
	for(int i=1;i<=q;i++) cout<<qr[i].ans<<'\n';
	return 0;
}
