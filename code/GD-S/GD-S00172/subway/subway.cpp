#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[114514],a[114514][100],t[114514][100],y,minn=114514;
struct itn{
	int sj;
	int sz;
};
itn ch[10086][10086];
int dfs(int x,int ti){
	if(x==y){
		return ti;
	}
	for(int i=1;i<=n;i++){
		if(ch[i][x].sj!=0){
			int tt=ch[i][x].sj;
			ch[i][x].sj=0;
			dfs(ch[i][x].sz,ch[i][ch[i][x].sz].sj+ti);
			ch[i][x].sj=tt;
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		int xx=0;
		for(int i=1;i<=k;i++){
			int x,y;
			cin>>x>>y;
			ch[i][x].sj=y;//第i条线，的第x站，要y时间 
			ch[i][xx].sz=x;
			xx=x;
		}
	}
	while(q--){
		int x;
		cin>>x>>y;
		cout<<dfs(x,w[x]);
		
	}
	return 0;
}
