#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,k;
bool vis[12222];
struct st{
	int x,y,z;
};
vector<st>m;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		vector<int>vt[12222];
		
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			vt[u].push_back(v);
			vt[v].push_back(u);
		}
		for(int i=1;i<=n;i++){
			vis[i]=1;
		}
		for(int i=1;i<=n;i++){
			if(!vis[i]){
				continue;
			}
			int ans=0,ass=1;
			queue<int>q;
			q.push(i);
			vis[i]=0;
			while(!q.empty()){
				ans++;
				int t=q.front();
				q.pop();
				for(int j:vt[t]){
					if(vis[j]){
						q.push(j);
						vis[j]=0;
						ass++;
					}
				}
			}
			m.push_back({i,ans,ass});
		}
		int min1=1000000,min=1000000,i1,i2,s=0;
		/*for(auto i:m){
			s++;
			if(min1>i){
				i1=s;
				min1=i;
			}
		}
		s=0;
		for(auto i:m){
			s++;
			if(min2>i){
				i1=s;
				min2=i;
			}
		}*/
		int ans=122222;
		for(int i=0;i<m.size();i++){
			for(int j=1;j<m.size();j++){
				if(m[i].z+m[j].z>=k){
					ans=max(m[i].z,m[j].z)
				}
			}
		}
		cout<<ans
	}
	return 0;
}	
