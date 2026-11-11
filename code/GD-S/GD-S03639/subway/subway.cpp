#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,p; 
int w[500005];
int vis[500005];
int dis[500005];
struct tu{
	int to;
	int q;
	int nxt;
	int from;
}a[500005];
int h[5000005];
int ss[500005];
int change[1005][1005];
int sum=1;
void in(int x,int y,int z){
	a[sum].to=y;
	a[sum].from=x;
	a[sum].q=z;
	a[sum].nxt=h[x];
	h[x]=sum;
	sum++;
}
void dij(int x,int come,int y,int fa){
//	cout<<x<<" "<<come<<" "<<dis[x]<<endl;
	for(int i=h[x];i;i=a[i].nxt){
		if(a[i].to==fa){
			continue;
		}
	//	cout<<a[i].to<<endl;
		if(come!=0&&come!=a[i].q){
			dis[a[i].to]=min(dis[a[i].to],dis[x]+change[come][a[i].q]+change[a[i].q][a[i].q]);
			dij(a[i].to,a[i].q,y,x);
		}
		else{
			dis[a[i].to]=min(dis[a[i].to],dis[x]+change[a[i].q][a[i].q]);
			dij(a[i].to,a[i].q,y,x);
		}
	}

}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	} 
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		int lk=0;
		for(int j=1;j<=x*2;j++){
			int k;
			cin>>k;
			if(j%2==1){
				if(lk!=0){
					in(lk,k,i);
					in(k,lk,i);
			//		cout<<k<<" "<<lk<<" "<<i<<endl;
				}
				lk=k;
			}
			else{
				change[i][lk]=k;
		//		cout<<i<<" "<<lk<<" "<<k<<" change"<<endl;	
			}
		}
	}
	for(int i=1;i<=p;i++){
		int x;
		int y;
		int ans=0;
		memset(vis,0,sizeof(vis));
		cin>>x>>y;
		dij(x,0,y,0);
		cout<<dis[y]+w[x]+change[1][x]+w[y]<<endl;
	}
	return 0;
}
