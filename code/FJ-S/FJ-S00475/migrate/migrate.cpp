#include<bits/stdc++.h>

const int N=2*1e6+5;
using namespace std;
int rdrd(){
	int n=0,f=1;char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		n=n*10+c-'0';
		c=getchar();
	}
	return n*f;
}
int c,t,n,d,v;
int x[N];
struct node{
	int disnum,minn=INT_MAX;
}dis[N];

void dfs(int i,int now,bool f){
	//cout<<i<<" "<<now<<" "<<f<<"\n";
	if(dis[v].disnum>2)return;
	if(i==v&&f){
		dis[i].minn=min(dis[i].minn,now);
		return;
	}else if(i==v&&!f){
		if(now==dis[v].minn){
			dis[v].disnum++;
			return;
		}
		return;
	}
	for(int j=i+1;j<=n;++j){
		if((x[j]-x[i])<=d){
			dfs(j,now+1,f);
		}
	}
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=rdrd();t=rdrd();
	while(t--){
		n=rdrd();d=rdrd();
		for(int i=1;i<=n;++i){
			dis[i].disnum=0;
			dis[i].minn=INT_MAX;
		}
		for(int i=1;i<=n;++i){
			x[i]=rdrd();
		}
		int ans=0;
		for(int i=1;i<=n;++i){
			for(int j=i;j<=n;++j){
				if(i==j)continue;
				v=j;
				dfs(i,0,1);
				dfs(i,0,0);
				for(int k=1;k<=n;++k){
					if(dis[k].disnum==2){
						ans++;
						//cout<<k<<" ";
					}
				}
				for(int i=1;i<=n;++i){
					dis[i].disnum=0;
					dis[i].minn=INT_MAX;
				}
			}
		}
		cout<<ans<<"\n";
	}
	/*
	0 2
	4 2
	1 2 3 4
	5 2
	1 2 3 4 5
	ans:1
		2
	0 2
	5 3
	-2 -1 0 1 2
	6 2
	-4 -3 -2 -1 3 6
	ans:0
		1
	*/
	return 0;
}
