#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,a[5005],dis[5005][5005],num[5005][5005];
//int to[2000005],val[2000005],nxt[2000005],h[5005],cnt,bj[5005][5005];
//void add(int u,int v,int w){
//	to[++cnt]=v;
//	val[cnt]=w;
//	nxt[cnt]=h[u];
//	h[u]=cnt;
//}
//priority_queue<pair<int,int> >q;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j)dis[i][j]=0x3fffffff;
			}
		}
		for(int i=2;i<=n;i++){
			for(int j=1;j<i;j++){
				if(a[i]-a[j]<=d){
//					add(j,i,1);
					dis[j][i]=1;
					num[j][i]=1;
				}
			}
		}
//		for(int i=1;i<=n;i++){
//			dis[i][i]=0;
//			q.push(make_pair(0,i));
//			while(!q.empty()){
//				int k=q.top().second;
//				q.pop();
//				if(bj[i][k]==1){
//					continue;
//				}
//				bj[i][k]=1;
//				for(int j=h[k];j;j=nxt[j]){
//					int v=to[j];
//					if(dis[i][v]>dis[i][k]+val[j]){
//						dis[i][v]=dis[i][k]+val[j];
//						num[i][v]=0;
//						q.push(make_pair(-dis[i][v],v));
//					}
//					if(dis[i][v]==dis[i][k]+val[j]){
//						num[i][v]++;
//					}
//				}
//			}
//		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(dis[i][k]+dis[k][j]==dis[i][j]){
						num[i][j]+=num[i][k]*num[k][j];
					}
					if(dis[i][k]+dis[k][j]<dis[i][j]){
						dis[i][j]=dis[i][k]+dis[k][j];
						num[i][j]=num[i][k]*num[k][j];
					}
				}
			}
		}
		int sum=0;
		for(int i=2;i<=n;i++){
			for(int j=1;j<i;j++){
				if(num[j][i]==2){
					sum++;
				}
			}
		}
		cout<<sum<<endl;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=num[i][j]=0;
			}
			a[i]=0;
		}
	}
	return 0;
} 

