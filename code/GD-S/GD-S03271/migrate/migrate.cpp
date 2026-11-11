#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int c,t,n,d,cnt,ans,mnv;
vector<int>s[N];
bool f;
void bfs(int st,int des){
	queue<pair<int,int>>q;
	vector<bool>vis(n,0);
	q.push({st,0});
	vis[st]=1;
	while(q.size()){
		auto [u,v]=q.front();
		q.pop();
		int l=s[u].size();
		for(int i=0;i<l;i++){
			if(!vis[s[u][i]]||s[u][i]==des&&v+1==mnv){
				vis[s[u][i]]=1;
				if(s[u][i]==des){
					if(!f)mnv=v+1;
					f=1;
					cnt++;
				}if(!f)q.push({s[u][i],v+1});
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
		vector<int>x(n+5);
		cin>>x[1];
		for(int i=2;i<=n;i++){
			cin>>x[i];
		}for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				if(x[j]-x[i]<=d){
					s[i].push_back(j);
				}
			}	
		}for(int i=1;i<n-1;i++){
			for(int j=i+2;j<=n;j++){
				bfs(i,j);
				f=0;
				if(cnt==2){
					ans++;
				}cnt=0,mnv=0;
			}	
		}cout<<ans<<endl;
		ans=0;
		for(int i=1;i<=n;i++){
			s[i].clear();
		}
	}
}

