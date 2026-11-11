#include<bits/stdc++.h>
using namespace std;
struct node{
	int xy,cost,cc;
};
int point[510000],to[10100000],per[10100000],cost[10100000];
int n,m,c,d,q;
int w[510000];
int li[510000];
int cc[510000];
long long cnt=0;
queue<node> s;
void add(int x,int y){
	cnt++;
	to[cnt]=y;
	per[cnt]=point[x];
	point[x]=cnt;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=510000;i++){
		cost[i]=1000000000;
	}
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			scanf("%d%d",&li[j],&cc[j]);
			for(int jj=1;jj<j;jj++){
				add(li[jj],li[j]);
				cost[cnt]=min(cc[j]+cc[jj],cost[cnt]);
				add(li[j],li[jj]);
				//cout<<li[jj]<<' '<<li[j]<<endl;
				cost[cnt]=min(cc[j]+cc[jj],cost[cnt]);
			}
		}
	}
	while(q--){
		int x,y;
		long long ans=1000000000;
		int vis[510000];
		for(int i=1;i<=m;i++){
			vis[i]=1000000000;
		}
		scanf("%d%d",&x,&y);
		node vv={x,w[x],0};
		s.push(vv);
		while(!s.empty()){
		//cout<<1;
			node u=s.front();
			//cout<<u.xy<<endl;
			s.pop();
			long long uu=u.cost;
			if(u.xy==y){
				ans=min(uu,ans);
				continue;
			}
			if(uu>=ans||u.cc>=m){
				continue;
			}
			for(int i=point[u.xy];i!=0;i=per[i]){
				int oo=to[i];
				//cout<<oo<<endl;
				if(u.cost>=vis[oo]){
					continue;
				}else{
					vis[oo]=u.cost;
					node vvv={oo,u.cost+cost[i],u.cc+1};
					s.push(vvv);
				}
			}
		}
		ans+=w[y];
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
