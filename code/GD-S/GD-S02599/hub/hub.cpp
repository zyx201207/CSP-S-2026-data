#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,t;
ll n,d;
ll a[200005];
ll value[2005][2005];
const int M=1e5+1;

void dij(int begin){
bool vis[m];
	priority_queue< pair<int , int>, vector<pair< int,int> >,greater< > > q;
	memset(vis,0,sizeof(vis));
	memset(dist,0x3f,sizeof(dist));
	dist[begin]=0;
	q.push({0,begin});
	while(!q.empty()){
		auto m=q.top();
		q.pop();
		int k=m.second;
		if(vis[k]==1) continue;
		vis[k]=1;
		for(auto v:g[k]){
			int dian=v.first;
			int value=v.second;
			if(dist[dian]>dist[k]+value){
			dist[dian]=dist[k]+value;
				q.push({dist[dian],dian});
			}
		}
	}
}
bool pan=0;
int main(){
	cin>>c>>t;
	while(t--){
		cin>>n>>>d;
		a[0]=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
			value[i][j]=a[j]-a[i];
		}
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
			if(value[i][j]!=value[i][j+1]){
				pan==2;
					
			}if(value[i][j]>d){
					pan==1;
				}
		
		}
		}
		
		if(pan==1) cout<<0;
		if(pan==2) cout<<n/2-1;
}
	
	
} 
