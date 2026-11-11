#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,a,las,kk,k,pre[500005],xx,yy;
long long w[500005],t,ans;
struct node{
	int to;
	int next;
	int xian;
}b[1000005];
//b[i].to:第i条边的终点
//b[i] .next:第i条边同起点的上一条边
//pre[i]:以i为起点的最后一条边 
void add(int x,int y,int in){
	kk++;
	b[kk].to=y;
	b[kk].next=pre[x];
	pre[x]=kk;
	b[kk].xian=in;
}
void dfs(int x,int now,int lasx){
	//cout<<endl;
	if(x==yy){
		//cout<<ans<<endl;
		ans=min(ans,now+t+w[x]);
		return;
	}
	for(int i=pre[x];i!=0;i=b[i].next){
		//cout<<i<<' ';
		if(x==xx) lasx=b[i].xian;
		if(lasx==b[i].xian) dfs(b[i].to,now,lasx);
		else dfs(b[i].to,now+2*t,b[i].xian);
	}
	//cout<<endl;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a>>t;
			if(j!=1){
				add(las,a,i);
				//add(a,las,i);
			}
			las=a;
		}
	}
	/*for(int i=1;i<=kk;i++) cout<<b[i].to<<' '<<b[i].next<<' '<<b[i].xian<<endl;
	cout<<endl;
	for(int i=1;i<=n;i++) cout<<pre[i]<<' ';*/
	while(q){
		q--;
		cin>>xx>>yy;
		ans=LLONG_MAX; 
		//cout<<2111<<endl;
		dfs(xx,w[xx]+t,0);
		cout<<ans<<endl;
	}
	return 0;
}
