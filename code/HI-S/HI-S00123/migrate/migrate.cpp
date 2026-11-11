#include<bits/stdc++.h>
using namespace std;
struct node{
	int now,sum;
};
int W[20010],l[20010],ans,n;
long long d;
void bfs(int u,int v){
	memset(l,0,sizeof(l));
	queue<node> Q;
	Q.push({u,0});
	while(!Q.empty()){
		node u = Q.front();
		Q.pop();
		if(u.now == v){
			l[u.sum]++;
			continue;
		}
		for(int i = u.now+1;i <= v;i++){
			if(W[i]-W[u.now] > d){
				break;
			}
			Q.push({i,u.sum+1});
		}
	}
	return;
}
int main(){
	freopen("migrate3.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>> c >> t;
	while(t--){
		cin>> n >> d;
		for(int i = 1;i <= n;i++){
			cin>> W[i];
		}
		ans = 0;
		for(int i = 1;i <= n;i++){
			for(int j = i+1;j <= n;j++){
			    bfs(i,j);
			    for(int k = 1;k <= 20010;k++){
			    	if(l[k] > 0){
			    		if(l[k] == 2){
			    		    ans++;
			    	    }
			    		break;
					}
				}
			}
		}
		cout<< ans << "\n";
	}
	return 0;
}
