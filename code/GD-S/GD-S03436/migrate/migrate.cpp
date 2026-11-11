#include<bits/stdc++.h>
using namespace std;

const int N=20010;
int c,t,n,d; //n:岛屿数量 d:鸟一次飞的最远距离 
int mp[N],minn[N][N],minnn=0x3f,ans=0,res=0;

void dfs(int x,int y){ //x为当前岛屿 y为目标岛屿
	res++;
	if(mp[y]-mp[x]>d || res>=minnn){
		return;
	}
	for(int i=y;i<=n;i++){
		dfs(y,i);
	}
}




int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> c >> t;
	for(int i=1;i<=t;i++){
		cin >> n >> d;
		memset(mp,0,sizeof mp);
		memset(minn,0x3f,sizeof minn);
		minnn=0x3f,ans=0;
		for(int i=1;i<=n;i++) cin >> mp[i];
		
		if(n<=9){
			for(int i=1;i<=n;i++){ //当前岛屿 
				int j;//飞到的岛
				int i1=i;
				for(j=i+1;j<=n;j++){
					res=0;
					dfs(i,j);
					minn[i][j] = min(minn[i][j],res);
					minnn=min(minnn,res); 
				}
			}
			for(int i=1;i<=n;i++){
				int cnt=0;
				for(int j=i+1;j<=n;j++){
					if(minn[i][j]==minnn) cnt++;
				}
				if(cnt==2) ans++;
			}
			cout << ans;
		}
	}
	return 0;
}
