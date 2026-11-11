#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,a[500005],k;
long long ans;
struct zhh
{
	int xl,wz;
};
struct node
{
	int di,t;
};
vector<node>b[505];//xian lu
vector<zhh>zh[500005];//zhan dian
void find(int x,int y,zhh xx,long long cnt)
{
	cout<<x<<endl;
	for(int i=xx.wz;i<b[xx.xl].size();i++)
	{
		node u=b[xx.xl][i];
		if(u.di==y){ans=max(ans,cnt);break;}
		int ll=zh[u.di].size();
		if(ll==1)continue;
		cnt+=u.t;
		for(int j=0;j<ll;j++)
		{
			if(zh[u.di][j].xl==xx.xl)continue;
			find(zh[u.di][j].wz,y,zh[u.di][j],cnt+b[zh[u.di][j].xl][j].t);
		}
	}
}
int main()
{
	//freopen("subway.in","r",stdin);
	//freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			node x;
			zhh as;
			cin>>x.di>>x.t;
			b[i].push_back(x);
			as.xl=i,as.wz=b[i].size();
			zh[x.di].push_back(as);
		}
	}
	for(int i=1;i<=q;i++){
		int l,r;
		cin>>l>>r;
		for(int j=0;j<zh[l].size();j++){
			find(l,r,zh[l][j],a[l]+b[zh[l][j].xl][zh[l][j].wz].t);
		}
		cout<<ans<<endl;
	}
	return 0;
}
