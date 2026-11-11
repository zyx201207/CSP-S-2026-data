#include<bits/stdc++.h>
using namespace std;
const int N=5005,inf=INT_MAX/2;
int c,t;
unsigned long long n,d;
long long x[N],dis[N],way[N],ans;
int h[N],nxt[N],cnt,to[N],ok[N];
void add(int u,int v){
	to[++cnt]=v;
	nxt[cnt]=h[u];
	h[u]=cnt;
}
void djstl(int s){
	priority_queue<pair<int ,int> > q;
	int k,v;
	for(int i=s;i<=n;i++){
		dis[i]=inf;
		way[i]=0;
		ok[i]=0;
	}
	dis[s]=0;
	q.push(make_pair(0,s));
	while(q.size()){
		k=q.top().second;
		q.pop();
		if(ok[k]) continue;
		ok[k]=1;
		
		for(int j=h[k];j;j=nxt[j]){
			v=to[j];
			if(dis[v]>dis[k]+1&&!ok[v]){
				dis[v]=dis[k]+1;
				way[v]=1;
				q.push(make_pair(-dis[v],v));
			}else if(dis[v]==dis[k]+1&&!ok[v]){
				way[v]++;
				q.push(make_pair(-dis[v],v));
			}
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		ans=0;
		for(int i=0;i<=cnt;i++){
			h[i]=0;
			nxt[i]=0;
			to[i]=0;
		}
		cnt=0;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			for(int j=i-1;x[i]-x[j]<=d&&j>0;j--){
//				printf("%d->%d\n",j,i);
				//add(i,j);
				add(j,i);
			}
		}
		for(int i=1;i<=n-2;i++){
			djstl(i);
//			for(int j=1;j<=n;j++){
//				cout<<dis[j]<<" ";
//			}cout<<endl;
//			for(int j=1;j<=n;j++){
//				cout<<way[j]<<" ";
//			}cout<<endl;
			for(int j=i;j<=n;j++){
				if(way[j]==2){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//n&d<=2*10^18,What can I say?8 points
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
