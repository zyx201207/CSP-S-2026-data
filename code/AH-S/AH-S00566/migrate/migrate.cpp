#include<bits/stdc++.h>
using namespace std;
int c,t,n;
#define N 2000006
typedef long long ll;
ll num[N],d;
struct node{
	int id,ste;
	bool operator <(const node a) const{
		return ste>a.ste;
	}
};
int dis[N],done[N],ans,sam;
void deal(int u){
	priority_queue<node> q;
	memset(dis,0x3f,sizeof(dis));
	memset(done,0,sizeof(done));
	q.push({u,0});
	dis[u]=0;
	node now;
	while(!q.empty()){
		now.id=q.top().id;
		now.ste=q.top().ste;
		q.pop();
		if(done[now.id]){
			if(now.ste==dis[now.id]){
				if(done[now.id]==1){
					ans++;
					done[now.id]++;
				}
				else if(done[now.id]==2){
					ans--;
					done[now.id]++;
				}
				else{
					continue;
				}
			}
		}
		else{
			done[now.id]++;
		}
		for(int i=now.id+1;i<=n;i++){
			if(num[i]-num[now.id]<=d){
				if(dis[i]>=now.ste+1){
					dis[i]=now.ste+1;
					q.push({i,dis[i]});
				}
			}
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	ll dif;
	int flag;
	while(t--){
		scanf("%d%lld",&n,&d);
		memset(num,0,sizeof(num));
		flag=1;
		for(int i=1;i<=n;i++){
			scanf("%lld",&num[i]);
			if(i>2){
				if(num[i]-num[i-1]!=dif){
					flag=0;
				}
			}
			dif=num[i]-num[i-1];
		}
		if(n<=500){
			ans=0;
			for(int i=1;i<=n;i++){
				deal(i);
			}
			printf("%d\n",ans);
		}
		else{
			if(flag==0){
				printf("0\n");
			}
			else{
				if(d<2*dif){
					printf("0\n");
				}
				else{
					sam=d/dif;
					sam*=2;
					sam--;
					printf("%d\n",max(0,n-sam));
				}
			}
		}
	}
	
	return 0;
} 
