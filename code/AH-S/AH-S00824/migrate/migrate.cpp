#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define MAXN 2000005
int c,t,n; 
int a[MAXN],d,dist[MAXN],dis[MAXN]; 
struct node{
	int nxt,id;
	bool operator <(const node &a ) const {
	    return nxt>a.nxt;
	} 
};
int ans,sum; 
int main(){ 
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	ll delta,ans,sum;
	int flag;
	while(t--){
		cin>>n>>d;
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(i>2){
				for(int i=1;i<=n;i++){
					flag=0;
				}
				delta=a[i]-a[i-1];
	 		}
		} 
		if(n<=9){
			for(int u=1;u<=n;u++){
				priority_queue<node> pq;
				memset(dis,0x3f,sizeof(dis));
				memset(dist,0,sizeof(dist));
 			    pq.push({u,0});
				node now;
				while(!pq.empty()){ 
	    			now.id=pq.top().id;
	    			now.id=pq.top().nxt;
	    			pq.pop(); 
	    			if(dist[now.id]==1){
	    				ans++;
					}else if(dist[now.id]>1){
						if(now.nxt==dis[now.id]&&dist[now.id]==2){
						    ans--;
						}else{
							continue;
						}
					}else{
						dist[now.id]++;
					}
					for(int i=now.id+1;i<=n;i++){
						if(a[i]-a[now.id]<=d){
							if(dis[i]>=now.nxt+1){
								dis[i]=now.nxt+1;
								pq.push({i,dis[i]});
							}
						}
					}
				}
			} 
			cout<<ans<<"\n"; 
		}else{ 
			if(flag==0){
				printf("0");
			}else{
				if(d<2*delta){
					printf("0");
		    	}			
	    	}
		}
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
