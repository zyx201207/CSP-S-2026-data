#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,k;
vector<int> mp[N]; 
class bcj{
	public:
		int f[N];
		void init(){
			for(int i=1;i<=n;i++){
				f[i]=i;
			}
		} 
		void fin(int k){
			return f[k]==k?k:f[k]==fin(f[k]);
		}
		void mer(int a,int b){
			int fa=fin(a),fb=fin(b);
			f[fb]=fa;
		}
}t1,t2;
bool vis[N];
void sol(){
	t1.init();
	t2.init();
	cin>>n>>k;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		mp[u].push_back(v);
		mp[v].push_back(u);
	}
	int minn=INT_MAX;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			queue<int> q;
			q.push(i);q.push(j);
			while(!q.empty()){
				
			}
		}
	}
}
int main(){
	int c,t;
	cin>>c>>t;
	while(t--) sol();
	return 0;
}
