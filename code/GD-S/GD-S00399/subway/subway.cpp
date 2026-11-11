#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=507,M=5e5+7;
int c,n,m,d,q;
int k[M],w[M],a[M];
//int w[M],k[N],a[N][M],b[N][M],c[N][M];//b代表从站厅n到站台m c代表从站台n到站厅m
//int dp[N][4];

const int kou=0,tai=1,ting=2;

vector<int>g[N][4];

struct Node{
	int x,len;
	int flag=kou;
	Node(){
		x=0,len=0;
	}
	Node(int _x,int _len,int _flag){
		x=_x,len=_len,flag=_flag;
	}
	bool operator<(Node node2){
		return len<node2.len;
	}
};

//void init(){
//	for(int i=1;i<=n;i++){
//		dp[i][i]=0;
//	}
//	for(int st=1;st<=n;st++){
//		priority_queue<Node,vector<Node>,greater<Node>>q;
//		q.push({st,0});
//		while(q.size()){
//			auto tmp=q.front();
//			q.pop();
//			
//		}
//	}
//}


int calc(int x,int y){
//	priority_queue<Node,vector<Node>,greater<Node>>q;
//	memset(dp,0x3f,sizeof(dp));
//	q.push({x,0,kou});
//	dp[x][kou]=0;
//	while(q.size()){
//		auto tmp=q.front();
//		int x=tmp.x,len=tmp.len,flag=tmp.flag;
//		if(flag==kou){
//			if(dp[x][ting]>dp[x][kou]+w[x]){
//				dp[x][ting]=dp[x][kou]+w[x];
//				q.push({x,dp[x][ting],ting});
//			}
//		}else if(flag==ting){
//			if(dp[x][kou]>dp[x][ting]+w[x]){
//				dp[x][kou]=dp[x][ting]+w[x];
//				q.push({x,dp[x][kou],kou});
//			}
//			
//		}
//	}
	return w[x]+w[y]+a[x]+a[y];
}


signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		int x1,y1;
		for(int j=1;j<=k[i];j++){
			cin>>x1>>y1;
			a[x1]+=y1;
		}
	}
	
//	init();
	
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<calc(x,y)<<'\n';
	}
	return 0;
} 
