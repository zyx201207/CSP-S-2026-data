#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int bi,g,n,f[5005][5005],h[5005][5005],u,y;
ll d,x[2000005],s;
vector<int> l[5005];
deque<int> q;
void bfs(int x){
	q.push_back(x);
	while(!q.empty()){
		for(auto &v:l[q.front()]){
			if(f[x][v]==0){
				f[x][v]=f[x][q.front()]+1;
				q.push_back(v);
			}
		}
		q.pop_front();
	}
	return ;
}
void aa(int i,int x,int s){
	if(s>f[i][x])return ;
	h[i][x]++;
	for(auto &v:l[x]){
		aa(i,v,s+1);
	}
	return ;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&bi,&g);
	while(g--){
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++)scanf("%lld",&x[i]);
		if(bi<=10){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(x[j]-x[i]<=d)l[i].push_back(j);
					else break;
				}
			}
			for(int i=1;i<=n;i++)bfs(i);
			for(int i=1;i<=n;i++)aa(i,i,0);
			s=0;
			for(int i=1;i<=n;i++){
				l[i].clear();
				for(int j=1;j<=n;j++){
					if(h[i][j]==2)s++;
					f[i][j]=0;
					h[i][j]=0;
				}
			}
			printf("%lld\n",s);
		}
		if(bi==11||bi==12){
			u=1;
			for(int i=2;i<=n;i++){
				if(x[i]-x[1]<=d)u=i;
				else break;
			}
			u--;
			s=0;
			if(u>0){
				for(int i=1;i<=n;i++){
					y=i+u-1+u;
					if(y<=n)s=s+1ll*((i-1)/u+1)*((n-y)/u+1);
				}
			}
			printf("%lld\n",s);
		}
	}
	return 0;
}
