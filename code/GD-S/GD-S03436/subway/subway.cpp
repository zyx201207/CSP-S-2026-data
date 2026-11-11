#include<bits/stdc++.h>
using namespace std;

const int N=200010;
int c,n,m,d,q;

struct Ti{
	int sub[N];
	int sta[N]; //第i条线路经过的第a[i]个地铁站 从展厅到站台时间为sta[i][] 
};

int ti[N]; //地铁站到站台间步行时间 
int sub[N]; //第i个站台总共经过sub[i]条线路 sub[i]为线路总数 
int a[N]; //第i条线路经过的第a[i]个地铁站 a[i]为地铁站编号 
Ti b;

int dp[10000][10000];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++){
		cin >> b.sub[i];
	}
	for(int i=1;i<=n;i++){
		cin >> sub[i];
		for(int j=1;j<=n;j++){
			cin >> a[j] >> b.sta[j];
		}
	}
	
	for(int i=1;i<=q;i++){
		memset(dp,0,sizeof dp);
		int x,y; //x为起点地铁编号 y为终点 
		cin >> x >> y;
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
				dp[i][j]=min(dp[i][j],dp[i][j-1]+b.sta[j]+b.sub[j]);
			}
		}
		cout << dp[x][y] << "\n";
	}
	return 0;
}
