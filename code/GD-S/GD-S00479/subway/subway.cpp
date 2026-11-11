#include<iostream>
#include<cstdio>
using namespace std;
int c,n,m,d,q;
long long w[500005];
int k[502];
struct way{
	int to,next;
	long long v;
}a[20000007];
int top,head[500005];
void add(int x,int y,long long v){
	top++;
	a[top].to=y;
	a[top].v=v;
	a[top].next=head[x];
	head[x]=top;
}
long long dis[502][502];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=1e16;
		}
		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++){
			int x;
			long long v;
			scanf("%d %lld",&x,&v);
			add(x,i,v);
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=head[i];j;j=a[j].next){
			for(int k=a[j].next;k;k=a[k].next){
				dis[a[j].to][a[k].to]=min(dis[a[j].to][a[k].to],a[j].v+a[k].v);
				dis[a[k].to][a[j].to]=dis[a[j].to][a[k].to];
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			if(i==k)continue;
			for(int j=i+1;j<=n;j++){
				if(j==k)continue;
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
				dis[j][i]=dis[i][j];
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		long long ans=1e16;
		scanf("%d %d",&x,&y);
		for(int j=head[x];j;j=a[j].next){
			for(int k=head[y];k;k=a[k].next){
				ans=min(ans,w[x]+a[j].v+dis[a[j].to][a[k].to]+a[k].v+w[y]);
			}
		}
		printf("%lld\n",ans);
	}
	/*
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<dis[i][j]<<' ';
		}
		cout<<endl;
	}
	*/
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/
