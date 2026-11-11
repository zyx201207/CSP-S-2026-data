#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q1,w[114514],k[114514],b[1145],e[1145],a[1145][1145],p[114514];
struct sans{
	int x;//地点
	int num;//step 
	bool h;//换乘 
};
int sanb(int be,int en,int num){
	int ans=1e10;
	queue<sans> q;
	q.push((sans){be,num,0});
	while(!q.empty()){
		sans g=q.front();
		q.pop();
		if(g.x==en){
			ans=min(ans,g.num);
			continue;
		}
		//cout<<p[g.x]<<" ";
		if(!g.h){
			if(a[g.x][g.x]!=0){
				q.push((sans){g.x,g.num+a[g.x][g.x],1});
			}
			continue;
		}
		for(int j=1;j<=m;j++){
			if(j==g.x)continue;
			if(a[g.x][j]==0)continue;
			if(p[j]>g.num+a[g.x][j]){
				q.push((sans){j,g.num+a[g.x][j],0});
				//cout<<g.x<<"->"<<j<<endl;
				p[j]=g.num+a[g.x][j];
			}
		}
	}
	return ans;
}

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q1;
	for(int i=1;i<=m;i++)cin>>w[i];//走入/走出 
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int o;//换乘
			cin>>o;
			cin>>a[i][o];
		}
	}
	for(int i=1;i<=q1;i++){
		cin>>b[i]>>e[i];
//		memset(p,1,sizeof(p));
		for(int l=1;l<=m;l++)p[l]=1e10;
		cout<<sanb(b[i],e[i],w[b[i]])+w[e[i]]<<endl;;
	}
	
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2


0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/

