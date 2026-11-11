#include<bits/stdc++.h>
using namespace std;
int c,t,n,mp[2001000],cnt;
long long sz[2001000],h[2000100],d;
#define PII pair<int,int>
priority_queue<PII> q;
void djs(int X){
	memset(mp,0x3f,sizeof mp);
	memset(sz,0,sizeof sz);
	q.push({0,X});
	mp[X]=0;sz[X]=1;
	while(!q.empty()){
		int x=q.top().second;q.pop();
		for(int i=x+1;i<=n;i++){
			if(h[i]-h[x]>d)break;
			if(mp[x]+1<mp[i]){
				mp[i]=mp[x]+1;
				sz[i]=0;
				q.push({-mp[i],i});
			}
			if(mp[x]+1==mp[i])sz[i]+=sz[x];
		}
	}
	for(int j=X+1;j<=n;j++)if(sz[j]==2){
		cnt++;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++)scanf("%lld",&h[i]);
		for(int i=1;i<=n;i++){
			//枚举以该点作为起点往后走?
			djs(i);
		}
		printf("%d\n",cnt);cnt=0;
	}
	return 0;
}
