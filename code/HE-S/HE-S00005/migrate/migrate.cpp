//delta=sqrt(b^2-4ac)
//wei sha bu kao shu lun a!
//wo fu xi le yi wan shang shu lun!
//wo shen zhi hui zheng ming oula theory!
//wo te yi xue le sheng yu xi!!!!!!
//wo hai hui sheng yu xi fu he!!!!!!
//WHY!!!!!!!!!!!!!!!!!
//My WC die die die /ll/ll/ll
//My MC go go go /kx/kx/kx
//ting yu de sheng yin
//yi di di qing xi
//ni de hu xi xiang yu di shen ru wo de ai li
//zhen xi wang yu neng xia bu ting
//rang xiang nian ji xv
//rang ai bian tou ming
//wo gan xie yong qi
//gei wo de rainy love
//40pts+-eps?

//Of course I can solve the Oula Theory:
//a^phi(m)=1(mod m)
//you xing zhi ke zhi phi(m)=|Zm*|
//18:00 Ok I forget it
//But I could
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=3e6;
int c,T,n,d,x[N],dis[N],cnt[N];
vector<int>g[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;++i){
			cin>>x[i];
			g[i].clear();
		}
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				if(abs(x[j]-x[i])<=d)g[i].push_back(j);
		int ans=0;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j)dis[j]=0,cnt[j]=0;
			queue<int>q;
			q.push(i);
			dis[i]=1,cnt[i]=1;
			while(q.size()){
				int u=q.front();
				q.pop();
				for(int j=0;j<(int)g[u].size();++j){
					int v=g[u][j];
					if(!dis[v])dis[v]=dis[u]+1,cnt[v]=1,q.push(v);
					else if(dis[u]+1<dis[v])dis[v]=dis[u]+1,cnt[v]=1,q.push(v);
					else if(dis[u]+1==dis[v])dis[v]=dis[u]+1,++cnt[v],q.push(v);
				}
			}
			for(int j=i;j<=n;++j)
				ans+=(cnt[j]==2);				
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
0 1
4 2
1 2 3 4
*/
