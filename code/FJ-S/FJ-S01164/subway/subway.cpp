#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,qq,dx[500005],sum,x,k,a[500005],t[500005],qx,qy;
long long b[200005];
struct Node{
	int to,val;
};
Node cc;
vector<Node>ne[1000005];
queue<int>q;
long long SPFA(int x,int y){
	for(int i=1;i<=sum;i++){
		b[i]=0x3f3f3f3f3f3f3f3f;
	}
	q.push(x);
	b[x]=0;
	while(!q.empty()){
		int ff=q.front();
		q.pop();
		for(int i=0;i<ne[ff].size();i++){
			if(b[ne[ff][i].to]>b[ff]+ne[ff][i].val){
				b[ne[ff][i].to]=b[ff]+ne[ff][i].val;
				q.push(ne[ff][i].to);
			}
		}
	}
	return b[y];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&m,&n,&d,&qq);
	for(int i=1;i<=n;i++){
		scanf("%d",dx+i);
		cc.to=n+i;
		cc.val=dx[i];
		ne[i].push_back(cc);
		cc.to=i;
		cc.val=dx[i];
		ne[n+i].push_back(cc);
	}
	sum+=n*2;
	x=2*n+1;
	for(int i=1;i<=m;i++){
		scanf("%d",&k);
		sum+=k;
		for(int j=1;j<=k;j++){
			scanf("%d%d",a+j,t+j);
			if(j!=1){
				x++;
				cc.to=x-1;
				cc.val=0;
				ne[x].push_back(cc);
				cc.to=x;
				ne[x-1].push_back(cc);
			}
			cc.to=n+a[j];
			cc.val=t[j];
			ne[x].push_back(cc);
			cc.to=x;
			ne[n+a[j]].push_back(cc);
		}
		x++;
	}
	for(int i=1;i<=qq;i++){
		scanf("%d%d",&qx,&qy);
		printf("%lld\n",SPFA(qx,qy));
	}
	return 0;
}
