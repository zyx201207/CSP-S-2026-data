#include<bits/stdc++.h>
using namespace std;
using ll=long long;

ll w[500005];
ll k[505];
ll a[505][50005],t[505][50005];
bool visd[50005];

struct node{
	ll g;
	ll s;
	ll p;
	ll cost;
};

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int c,n,m,d,r; cin>>c>>n>>m>>d>>r;
	
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	while(r--){
		int x,y; cin>>x>>y;
		memset(visd,false,sizeof(visd)); 
		queue<node>q;
		ll ans=w[x]+w[y];
		ll ssum=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k[i];j++){
				if(a[i][j]==x){
					ssum++;
					q.push({i,x,t[i][j],ans});
				}
			}	
		}
		bool had_ans=false;
		ll sum=0;
		ll id=0;
		while(!q.empty()){
			//cout<<"aaa"<<endl;
			node cur=q.front();
			q.pop();
			
			if(visd[cur.s])continue;
			visd[cur.s]=true;
			if(sum>=ssum)break;
			if(cur.s==y){
				//cout<<"AAA\n";
				sum++;
				if(had_ans)ans=min(ans,cur.cost+cur.p);
				else ans=cur.cost+cur.p;
				had_ans=true;
				continue;
			}
			for(int i=1;i<=n;i++){
				for(int j=1;j<=k[i];j++){
					if(a[i][j]==cur.s){
						ll o=0;
						if(id==0)o=t[i][j];
						if(i!=cur.g){
							if(j>1&&!visd[a[i][j-1]])q.push({i,a[i][j-1],t[i][j-1],cur.cost+t[i][j-1]+t[i][j]+o});
							if(j<k[i]&&!visd[a[i][j+1]])q.push({i,a[i][j+1],t[i][j+1],cur.cost+t[i][j+1]+t[i][j]+o});
						}
						else{
							if(j>1&&!visd[a[i][j-1]])q.push({i,a[i][j-1],t[i][j-1],cur.cost});
							if(j<k[i]&&!visd[a[i][j+1]])q.push({i,a[i][j+1],t[i][j+1],cur.cost});
						}
						break;
					}
				}	
			}
			id++;
		}
		cout<<ans<<'\n';
		
	}
	
	
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

