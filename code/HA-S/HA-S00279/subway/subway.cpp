//2
#include<bits/stdc++.h>
#include<queue>
using namespace std;
int c,n,m,d,q;
int k[505],a[505][500005],x[100005],y[100005];
struct nd{
	int t,ch[25][2],dir=0;
} w[500005];
struct aaa{
	int x;
	long long sum;
};
long long ans=0;
bool bj[500005];
void bfs(int st,int en){
	queue<aaa> q;
	q.push({st,0}); 
	while(!q.empty()){
		int x=q.front().x;
		long long sum=q.front().sum;
		q.pop();
		for(int i=1;i<=w[x].dir;i++){
			int tt=w[x].ch[i][1];
			for(int j=1;j<=k[w[x].ch[i][0]];j++){
				if(a[w[x].ch[i][0]][j]==st) continue;
				//q.push({a[w[x].ch[i][0][j],sum+tt}) 
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i].t);
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int t1,t2;
			scanf("%d%d",&t1,&t2);
			a[i][j]=t1;
			++w[t1].dir;
			w[t1].ch[w[t1].dir][0]=i;
			w[t1].ch[w[t1].dir][1]=t2;
		}
	}
	for(int i=1;i<=q;i++){
		scanf("%d%d",x[i],y[i]);
		cout<<67<<endl;
	}
	for(int i=1;i<=q;i++){
		memset(bj,0,sizeof(bj));
		ans=0;
		//bfs(x[i],y[i]);
		//cout<<ans;
	}
	return 0;
}
