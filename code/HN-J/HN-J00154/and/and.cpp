#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,cnt;
long long a[200010];
vector<long long> b;
bool vis[200010];
void dfs(long long d,long long sum){
	if(d>=m){
	   ans=max(ans,sum);
	   return;	
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			if(d==0){
				vis[i]=true;
				b.push_back(a[i]);
				dfs(d+1,a[i]);
				b.pop_back();
				vis[i]=false;
			}else{
				vis[i]=true;
				b.push_back(a[i]);
			    dfs(d+1,sum&a[i]);
				b.pop_back();	
			    vis[i]=false;
			}		
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}	
	dfs(0,0);
	cout<<ans;
	return 0; 
}
