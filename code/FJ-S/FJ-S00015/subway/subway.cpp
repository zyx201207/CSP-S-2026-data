#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int w[N],k[N];
struct Node{
	int a1,t1,a2,t2;
}p[N];
bool cmp(Node x,Node y)
{
	if(x.a1!=y.a1)return x.a1<y.a1;
	else return x.t1<y.t1;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			int a,t;
			cin>>a>>t;
			if(j==1)
			{
				p[i].a1=a;
				p[i].t1=t;
			}
			if(j==2)
			{
				p[i].a2=a;
				p[i].t2=t;
			}
		}
	}
	sort(p+1,p+1+n,cmp);
	while(q--)
	{
		long long ans=0;
		int x,y;
		cin>>x>>y;
		bool f=0;
		for(int i=1;i<=n;i++)
		{
			if(p[i].a1==x&&p[i].a2==y)
			{
				ans=w[x]+w[y]+p[i].t1+p[i].t2;
				break;
			}
			if(p[i].a1==x||p[i].a2==x)f=1;
			if(f==1)ans+=w[p[i].a1]+w[p[i].a2]+p[i].t1+p[i].t2;
			if(p[i].a2==y)break;
			
		}
		cout<<ans<<"\n";
	}
	return 0;
}
