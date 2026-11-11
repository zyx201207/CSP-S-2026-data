#include<bits/stdc++.h>
using namespace std;
#define int long long
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
typedef pair<int,int> PII;
const int N=514;
const int M=5e5+114;
int c,n,m,d,q;
int w[M];
int k[N];
int x[N],y[N];

//vector<PII>kto[N];
//vector<PII>ato[M];
//void input(){
//	cin>>n>>m>>d>>q;
//	for(int i=1;i<=m;i++){
//		cin>>w[i];
//	}
//	for(int i=1;i<=n;i++){
//		cin>>k[i];
//		for(int j=1;j<=k[i];j++){
//			int tmpa,tmpt;
//			cin>>tmpa>>tmpt;
//			kto[i].push_back({tmpa,tmpt});
//			ato[tmpa].push_back({i,tmpt});
//		}
//	}
//	for(int i=1;i<=q;i++){
//		cin>>x[i]>>y[i];
//	}
//}
void solve1(){
	int dis[1600][1600];
	memset(dis,0x3f,sizeof(dis));
	cin>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int tmpa,tmpt;
			cin>>tmpa>>tmpt;
			dis[i+m][tmpa]=dis[tmpa][i+m]=tmpt;
		}
	}
	for(int k=1;k<=n+m;k++){
		for(int i=1;i<=n+m;i++){
			if(i==k)continue;
			for(int j=1;j<=n+m;j++){
				if(j==i)continue;
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int tx,ty;
		cin>>tx>>ty;
		cout<<dis[tx][ty]+w[tx]+w[ty]<<endl;
	}
}
void solve2(){
	int dis[(int)5e5+510][(int)5e5+510];
	memset(dis,0x3f,sizeof(dis));
	cin>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int tmpa,tmpt;
			cin>>tmpa>>tmpt;
			dis[i+m][tmpa]=dis[tmpa][i+m]=tmpt;
		}
	}
	for(int k=1;k<=n+m;k++){
		for(int i=1;i<=n+m;i++){
			if(i==k)continue;
			for(int j=1;j<=n+m;j++){
				if(j==i)continue;
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int tx,ty;
		cin>>tx>>ty;
		cout<<dis[tx][ty]+w[tx]+w[ty]<<endl;
	}
}


signed main(){
	IOS
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c;
	cin>>c;
	if(c<=11)solve1();
	else solve2();
	return 0;
}
