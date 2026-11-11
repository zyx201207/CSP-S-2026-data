#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read(){
	ll x=0;
	char c=getchar();
	while(c<'0' || c>'9'){
		c=getchar();
	}
	while(c>='0' && c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}
const int N=500005;
int c,n,m,D,Q,k[N];//测试点 线路 地铁站 maxn 询问 线路经过站数 
ll W[N];//厅 -> 口 
vector<int> a[N];//线路 
vector<ll> t[N]; //厅 -> 台 
//void qwq(){
//	考生不能在注释中写侮辱性话语、歌词、诗词、散文等与考试无关的话语，若有违反可能会收到取消成绩或以上处分。
//	return;
//}
void ovo(){//A + 1~6暴力 
	vector< pair<int,ll> > e[1005];
//	/*
	for(int i=1;i<=n;i++){
		for(int j=0;j<k[i];j++){
			for(int p=j+1;p<k[i];p++){
				int u=a[i][j],v=a[i][p];ll w=t[i][j]+t[i][p];
//				printf("%d %d %lld\n",u,v,w);
				e[u].push_back(make_pair(v,w)),e[v].push_back(make_pair(u,w));
			}
		}
	}
//	printf("check");
	ll d[1005][1005];
	for(int i=1;i<1005;i++){
		for(int j=1;j<1005;j++){
			d[i][j]=0x7fffffff;
		}
	}
	while(Q--){
		int x,y;
		scanf("%d%d",&x,&y);
//		int x=read(),y=read();
		if(d[x][y]<0x7fffffff){
			printf("%lld\n",d[x][y]+W[x]+W[y]);
			continue;
		}
		int f[1005]={0};
		d[x][x]=0;
		priority_queue< pair<ll,int> > q;
		q.push(make_pair(0,x));
		while(!q.empty()){
			int u=q.top().second;
			q.pop();
			if(f[u]){
				continue;
			}
			f[u]=1;
			for(int i=0;i<e[u].size();i++){
				int v=e[u][i].first;ll w=e[u][i].second;
				if(d[x][v]>d[x][u]+w){
					d[x][v]=d[x][u]+w;
					if(!f[v]){
						q.push(make_pair(-1*d[x][v],v));
					}
				}
			}
//			printf("check:%lld\n",d[x][u]);
		}
//		printf("check\n");
		printf("%lld\n",d[x][y]+W[x]+W[y]);
	}
//	*/
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),D=read(),Q=read();
	for(int i=1;i<=m;i++){
		W[i]=read();
	}
	for(int i=1;i<=n;i++){
		k[i]=read();
		for(int j=1,x,y;j<=k[i];j++){
			x=read(),y=read();
			a[i].push_back(x),t[i].push_back(y);
		}
	}
	if(c<=11){
		
		ovo();
	}
//	qwq();
	return 0;
}
