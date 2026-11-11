#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll =long long;
using pii = pair<int, int>;
const int N=5e5+700,M=507,inf=1e9+9;
const ll INF=1e18+9;

ll f[M][M];//两个节点的最小价值
ll tran[N]; 
int tot;//总的节点个数 

vector<pii> ve[N];
void solved(){
	int n,m,d,q;cin>>n>>m>>d>>q;
	tot=m;//等会连虚点要用 
	for(int i=1;i<=m;i++)cin>>tran[i];
	
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		tot++;//当前虚点编号 
		for(int j=1;j<=k;j++){
			int x;int w;cin>>x>>w;
			ve[x].push_back({tot,w});//站台连单向，常数其实不大 
		}
	}//第一步 
	
	for(int i=m+1;i<=tot;i++){
		for(int j=m+1;j<=tot;j++){//这里会有问题，要转回去 
			if(i!=j)f[i-m][j-m]=INF;
//			cout<<"test "<<i<<' '<<j<<' '<<f[i][j]<<endl;
		}
		
	}
		
			
	for(int i=1;i<=m;i++){//枚举每个节点，然后更新线路
	 
		if(ve[i].size()<=1)continue;//当只有一条线路通过不管怎样都通过不了 
		
		for(int j=0;j<ve[i].size();j++){
			
			int x=ve[i][j].first,wx=ve[i][j].second;
			
			for(int k=j+1;k<ve[i].size();k++){
				int y=ve[i][k].first,wy=ve[i][k].second;	
				f[x-m][y-m]=f[y-m][x-m]=min(f[x-m][y-m],(ll)wx+wy);	
			}
		}
	}//第二步 
	
	
	for(int i=m+1;i<=tot;i++){
		for(int j=m+1;j<=tot;j++){
			for(int k=m+1;k<=tot;k++){
				f[i-m][j-m]=min(f[i-m][j-m],f[i-m][k-m]+f[k-m][j-m]);
			}
		}
	}//第三步
	
	while(q--){
		int st,ed;cin>>st>>ed;
		ll ans=INF;
		//到了这一步，我们当然可以再开一个数组
		for(int i=0;i<ve[st].size();i++){
			int x=ve[st][i].first,wx=ve[st][i].second;
			for(int j=0;j<ve[ed].size();j++){
				int y=ve[ed][j].first,wy=ve[ed][j].second;
				ans=min(ans,f[x-m][y-m]+wx+wy);
			}
			
		} 
		ans+=tran[st]+tran[ed];//地铁口到站厅时间
		cout<<ans<<endl;
	} 
	
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
 
32 17
fc subway4.out subway4.ans
*/
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int num;cin>>num;
	solved();
	return 0;
} 
/*
keep thinking  determined  calmed down!
最后，总结一下大体流程 

我们先建虚点，连接边
然后对于每个站点拆分出它的所有线路
然后我们进行从前往后 m/2 ^2 的对线路之间连接的更新，这样只需要2e7
接着，我们跑一遍 n^3 的更新
最后，我们 对于每个询问 ， 用 d<=20 的性质
d^2 的处理出 ， 线路之间最短距，得到答案 
此致 ， solved 
哦，发现了还有地铁口走到站厅，不过无所谓，只是加上两个价值即可 
注意到一件惊人事实是我们其实不需要这样连边，只需要从站台连单向
因为我们是在枚举站台 
拿下了 
*/





