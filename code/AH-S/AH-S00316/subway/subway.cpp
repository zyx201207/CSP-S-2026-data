/*从文件 subway.in 中读入数据。
输入的第一行包含五个非负整数 c, n, m, d, q,分别表示测试点编号、地铁线路数、
地铁站数、每个地铁站最多被几条线路经过,以及出行计划数。特别地,若 c = 0,则
该测试点为样例。
输入的第二行包含 m 个正整数 w 1 , w 2 , . . . , w m ,依次表示从每个地铁站的地铁口走
到站厅需要的时间。
输入的第 i + 2 (1 ≤ i ≤ n) 行包含 1 + 2k i 个正整数,其中第一个正整数为 k i ,表
示第 i 条线路经过的地铁站数;接下来 2k i 个正整数为 a i,1 , t i,1 , a i,2 , t i,2 , . . . , a i,k i , t i,k i ,其
中 a i,j 表示第 i 条线路经过的第 j 个地铁站,t i,j 表示从该地铁站的站厅走到第 i 条线
路的站台需要的时间。
输入的第 r + n + 2 (1 ≤ r ≤ q) 行包含两个正整数 x r , y r ,分别表示第 r 个出行计
划的起点和终点所在的地铁站编号

对于所有测试数据,均有:
• 0 ≤ c ≤ 25,1 ≤ n ≤ 500,1 ≤ m ≤
∑ n
i=1
k i ≤ 5 × 10 5 ,1 ≤ d ≤ 20,1 ≤ q ≤ 10 5 ;
• 对于所有 v (1 ≤ v ≤ m),均有 1 ≤ w v ≤ 10 9 ;
• 对于所有 i (1 ≤ i ≤ n),均有 1 ≤ k i ≤ m;
• 对于所有 i, j (1 ≤ i ≤ n, 1 ≤ j ≤ k i ),均有 1 ≤ a i,j ≤ m,1 ≤ t i,j ≤ 10 9 ;
• 对于所有 i (1 ≤ i ≤ n),均有 a i,1 , a i,2 , . . . , a i,k i 两两不同;
• 对于所有 v (1 ≤ v ≤ m),经过第 v 个地铁站的线路数均不超过 d;
• 任意两个地铁站都可以通过若干条线路互相到达;
特殊性质 A:每条线路至多经过 2 个地铁站,即对于所有 i (1 ≤ i ≤ n),均有 k i ≤ 2。
特殊性质 B:对于所有线路经过的所有地铁站,从站厅走到对应线路站台的步行时
间都相同,即存在正整数 T ,使得对于所有 i, j (1 ≤ i ≤ n, 1 ≤ j ≤ k i ),均有 t i,j = T 。*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct lin{
	ll x,t;
};
ll c,tt,n,m,d,q,w[500005],f[605][605];
vector<ll>a[505],t[505];
vector<lin>s[500005];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	tt=clock();
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		ll k;
		cin>>k;
		for(int j=1;j<=k;j++){
			ll a1,t1;
			cin>>a1>>t1;
			a[i].push_back(a1);
			t[i].push_back(t1);
			s[a1].push_back({i,t1});
		}
	}
	if((n+m)<=600){//floyd
		int siz=n+m;
		for(int i=1;i<=siz;i++){
			for(int j=1;j<=siz;j++){
				f[i][j]=0x3f3f3f3f3f3f3f3f;
			}
			f[i][i]=0;
		}
		for(int i=1;i<=n;i++){
			for(int j=0;j<a[i].size();j++){
				f[i+m][a[i][j]]=min(f[i+m][a[i][j]],t[i][j]);
				f[a[i][j]][i+m]=min(f[a[i][j]][i+m],t[i][j]);
			}
		}
		for(int i=1;i<=siz;i++){
			for(int j=1;j<=siz;j++){
				for(int k=1;k<=siz;k++){
					f[j][k]=min(f[j][k],f[j][i]+f[i][k]);
				}
			}
		}
		while(q--){
			int x,y;
			cin>>x>>y;
			cout<<f[x][y]+w[x]+w[y]<<"\n";
		}
	}else{
	/*
		* We've noticed that n and d was small compared to m.
		* Also,m*d*d and q*d*d <=10^8.
		* So we can use floyd to generate the shortest time to travel between the lines.
		*/
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=0x3f3f3f3f3f3f3f3f;
			}
			f[i][i]=0;
		}
		for(int i=1;i<=m;i++){
		//	cout<<i<<"\n";
			for(int j=0;j<s[i].size();j++){
		//		cout<<s[i][j].x<<" "<<s[i][j].t<<"\n";
				for(int k=j+1;k<s[i].size();k++){
					f[s[i][j].x][s[i][k].x]=min(f[s[i][j].x][s[i][k].x],s[i][j].t+s[i][k].t);
					f[s[i][k].x][s[i][j].x]=min(f[s[i][k].x][s[i][j].x],s[i][j].t+s[i][k].t);
				}
			}
		//	cout<<"\n";
		}
		
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++){
					f[j][k]=min(f[j][k],f[j][i]+f[i][k]);
				}
			}
		}
		while(q--){
			ll x,y,mn=0x3f3f3f3f3f3f3f3f;
			cin>>x>>y;
			for(int i=0;i<s[x].size();i++){
				for(int j=0;j<s[y].size();j++){
					int t1=s[x][i].x,t2=s[y][j].x;
					mn=min(mn,w[x]+w[y]+s[x][i].t+s[y][j].t+f[t1][t2]);
					//cout<<s[x][i].x<<" "<<s[y][j].x<<" "<<w[x]+w[y]<<" "<<s[x][i].t<<" "<<s[y][i].t<<" "<<f[t1][t2]<<"\n";
				}
			}
			cout<<mn<<"\n";
		}
	//	cout<<clock()-tt<<" "<<CLOCKS_PER_SEC;
	}
	return 0;
}
