#include <bits/stdc++.h>
#define int long long
using namespace std;
struct Node{
    int tx,ty;
}a[500010];
int b[510][500010],v[500010],k[501];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q,w;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>a[i].tx;
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>b[i][j]>>a[b[i][j]].ty;
			v[b[i][j]]--;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(v[i]==-2)
		{
			w=i;
			break;
		}
	}//换乘站
	int w1,w2;
	for(int i=1;i<=k[1];i++)
	{
		if(b[1][i]==w) w1=i;
		break;
	}
	for(int i=1;i<=k[2];i++)
	{
		if(b[2][i]==w) w2=i;
		break;
	}
	for(int z=1;z<=q;z++)
	{
		int x,y,s1=0,s2=0,ans=0,xi,yi,px=0;
		cin>>x>>y;
		for(int j=1;j<=k[1];j++)
		{
			if(b[1][j]==x) s1--,xi=j,px=1;
			else if(b[1][j]==y) s1--,yi=j;
		}
		for(int j=1;j<=k[2];j++)
		{
			if(b[2][j]==x) s2--,xi=j;
			else if(b[2][j]==y) s2--,yi=j;
		}
		if(s1==-2)//一条线1
		{
			ans+=a[x].tx+a[y].tx;
			for(int i=min(xi,yi);i<=max(xi,yi);i++)
			{
				ans+=a[b[1][i]].ty;
			}
			cout<<ans<<endl;
			continue;
		}
		else if(s2==-2)//一条线2
		{
			ans+=a[x].tx+a[y].tx;
			for(int i=min(xi,yi);i<=max(xi,yi);i++)
			{
				ans+=a[b[2][i]].ty;
			}
			cout<<ans<<endl;
			continue;
		}
		else{
			if(px==1){
				for(int i=min(xi,w1);i<=max(xi,w1);i++) ans+=a[b[1][i]].ty;
				for(int i=min(yi,w1);i<=max(yi,w1);i++) ans+=a[b[2][i]].ty;
			}
			else{
				for(int i=min(xi,w1);i<=max(xi,w1);i++) ans+=a[b[2][i]].ty;
				for(int i=min(yi,w2);i<=max(yi,w2);i++) ans+=a[b[1][i]].ty;
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
