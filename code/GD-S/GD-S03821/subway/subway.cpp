#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int const N=5e5+5;
int w[N],t[505][N];
vector<int>r[N];
bool f[N];
int ans=1e9;
void dfs(int x,int y,int cnt){
	if(x==y){
		bool v=0;
		for(int u:r[x]){
			if(u)v=1;
		}if(v)ans=min(ans,cnt+t[x][y]);
		else ans=min(ans,cnt+t[x][0]);
		return;
	}           
	for(int u:r[x]){
		dfs(u,y,cnt+t[x][u]);
	}return;	   
}					
int main(){			 
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;		
	cin>>c>>n>>m>>d>>q;  
	for(int i=1;i<=m;i++){
		cin>>w[i];		   
	}for(int i=1;i<=n;i++){ 
		int k,b=0,tu;cin>>k; 
		for(int j=1;j<=k;j++){
			int a;cin>>a;     
			if(b)r[b].push_back(a),t[b][a]=tu;
			cin>>tu;             
			b=a;                  
		}t[b][0]=tu;               
	}for(int i=1;i<=q;i++){         
		int x,y;cin>>x>>y;           
		dfs(x,y,w[x]+w[y]);           
		cout<<ans<<endl;               
		ans=1e9;                        
	}                                    
	return 0;                             
}                                          
