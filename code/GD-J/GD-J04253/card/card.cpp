#include <bits/stdc++.h>
#define int long long
#define rk(i,l,r) for(int i = l;i<=r;++i)
#define rp(i,r,l) for(int i = r;i>=l;--i) 
#define pb push_back
#define pp pop_back
using namespace std;
const int N =5e6+10;
int a[N],n,m,ans[N],pos[N],id[N],vis[N],kk[N],pre[N];
int st[N],tot,dt;
vector<int> vv;
signed main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	rk(i,1,n)cin>>a[i];
	reverse(a+1,a+n+1);
	pos[0]=0;
	rk(i,1,n+1)
	{
		if(!vis[a[i]]&&i<=n)
		{
			pre[i]=pos[a[i]];
			vis[a[i]]++,vv.pb(i),pos[a[i]]=vv.size()-1,id[i]=tot+1,st[++tot]=1;
			kk[a[i]]=i;	

		}
		else
		{ 
			while(vv.size()!=pos[a[i]]&&vv.size())
			{
				dt+=st[tot--]; 
				int x = vv.back();
				//vis[a[x]]--;
				//if(a[x]!=a[i])pos[a[x]]=pre[i];
				vv.pp();
				ans[a[x]]+=dt;
			}
			//vis[a[i]]++;
			vv.pb(i),pos[a[i]]=vv.size()-1,id[i]=tot+1,st[tot]+=dt,st[++tot]=1;dt=0;
		}
//		cerr<<i<<endl;
//		kk[a[i]]=i;
//		for(auto i:vv)cerr<<a[i]<<" ";cerr<<"\n";
//		rk(i,1,tot)cerr<<st[i]<<" ";
//		cerr<<endl;
	}
	rk(i,1,m)
	{
		cout<<ans[i]<<" \n"[i==m];
	}
	return 0;
}
