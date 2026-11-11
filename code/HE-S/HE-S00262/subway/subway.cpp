#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500010],k[510];
long long dis[510][510];
vector<int>t[510],jg[500010];
unordered_map<int,int>mp;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1,x,y;j<=k[i];j++){
			cin>>x>>y;
			t[i].push_back(y);
			mp[i*(m+1)+x]=y;
			jg[x].push_back(i);
		}
	}/*
	for(int i=1;i<=m;i++){
		for(int j=0;j<jg[i].size();j++){
			cout<<jg[i][j]<<" ";
		}
		cout<<"\n";
	}*/
	memset(dis,0x3f,sizeof(dis));/*
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int x=0;x<k[i];x++){
				if(mp[j*(m+1)+a[i][x]]){
					dis[i][j]=dis[j][i]=t[i][x]+mp[j*(m+1)+a[i][x]];
				}
			}
		}
	}*/
	for(int i=1;i<=m;i++){
		for(int x=0;x<jg[i].size();x++){
			for(int y=0;y<jg[i].size();y++){
				if(x==y)continue;
				dis[jg[i][x]][jg[i][y]]=dis[jg[i][y]][jg[i][x]]=mp[jg[i][x]*(m+1)+i]+mp[jg[i][y]*(m+1)+i];				
			}
		}
	}
	/*
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<dis[i][j]<<" ";
		}
		cout<<"\n"; 
	}*/
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}/*
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<dis[i][j]<<" ";
		}
		cout<<"\n"; 
	}*/
	int x,y;
	while(q--){
		cin>>x>>y;
		long long ans=1e18; 
		for(int i=0;i<jg[x].size();i++){
			for(int j=0;j<jg[y].size();j++){
//				cout<<jg[x][i]<<" "<<jg[y][j]<<" "<<mp[jg[x][i]*(m+1)+x]<<" "<<mp[jg[y][j]*(m+1)+y]<<" "<<t[jg[y][j]][x]<<"\n";
				ans=min(ans,dis[jg[x][i]][jg[y][j]]+mp[jg[x][i]*(m+1)+x]+mp[jg[y][j]*(m+1)+y]);
			}
		}
		cout<<w[x]+w[y]+ans<<"\n";
	}
	return 0;
}







/*

15:08开始看T2 
啥猎奇描述

15:15严肃没看懂 

15:29看懂了，floyd 

啥破地铁一条线经过1e5个站
不是这咋建图啊 

样例咋复制不了
 
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

15:57样例不过 
才看见d<=20 

16:33样例终于过了了了了了了了了了了了了了了了 
大样例怎么这么慢
我是**吗没删调试

还是这么慢 

500000*500
2.5*1e8*?


16:59改了改，快了不少
m*d^2 

就这样吧 
*/
