#include<bits/stdc++.h>
//#define int long long
using namespace std;
const int N=505;
int c,n,m,d,q; 
int w[N];
int k[N];//k[i]代表第i条线路经过的地铁站数量 
struct sta{
	int a,t;
}mp[N][N];
int ans[N][N];
bool lu[N][N];//lu[i][j]=1说明第i个站存在于第j号线
int zhan[N];//换线站=1 
bool now_used[N];
int ans1=0x3f3f; 
int smans=0;
void f(int x,int y){
	//cout<<smans<<"\n";
	deque <int> poq;//当前可以通过的路线 
	deque <int> zh;//换乘站台编号 
	for(int i=1;i<=n;i++){
		if(lu[x][i]==1&&now_used[i]!=1){
			poq.push_back(i);
		}
	}
	//if(poq.empty())
	while(!poq.empty()){
		int i=poq.front();
		//cout<<"走"<<i<<"号线";
		poq.pop_front();
		smans+=mp[i][x].t;
		//cout<<mp[i][x].t<<"\n";
		for(int j=1;j<=k[i];j++){
			if(mp[i][j].a==y){
				smans+=mp[i][y].t;
				smans+=w[y];
				//cout<<"到了"<<"\n";
				//cout<<smans<<"\n";
				ans1=min(ans1,smans);
				return ;
			}
			if(zhan[mp[i][j].a]>1){
				zh.push_back(mp[i][j].a);
			}
		}
		//if(zh.empty()) return ;
		//cout<<"有站"<<"\n";
		now_used[i]=1;
		while(!zh.empty()){
			//cout<<"转"<<zh.front()<<"站"<<"\n";
			smans+=mp[i][zh.front()].t;
			//cout<<mp[i][zh.front()].t;
			//now_used[i]=1;
			zhan[zh.front()]-=1;
			f(zh.front(),y);
			//cout<<"出"<<zh.front()<<"站"<<"\n";
			smans-=mp[i][zh.front()].t;
			zh.pop_front();
		}
		now_used[i]=0;
		smans-=mp[i][x].t;
	}
	return ;
	
}
signed main(){//m个地铁站 n条线路 每个地铁站最多d条线路 有q次询问（）  
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	//fill(ans+N,ans+N*N,-1);
	cin>>c>>n>>m>>d>>q;//c=0 就是样例 
	//
	for(int i=1;i<=m;i++){
		cin>>w[i];
		//cout<<w[i]<<" ";
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>mp[i][j].a>>mp[i][mp[i][j].a].t;//a是我i号线第j个经过的站的编号 从站厅走到本身的i号线或i走到站厅耗时为t
			lu[mp[i][j].a][i]=1;
			zhan[mp[i][j].a]+=1;
		}
	}
	for(int i=0;i<q;i++){
		fill(now_used,now_used+N,0);
		int x,y;
		//poq.clear();
		cin>>x>>y;
		if(ans[x][y]!=0) cout<<ans[x][y]<<"\n";
		else{
			smans=w[x];
			f(x,y);
			//cout<<1<<"\n";
			ans[x][y]=ans1;
			ans[y][x]=ans[x][y];
			smans=0;
			ans1=0x3f3f;
			cout<<ans[x][y]<<"\n";
		}
	} 
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
