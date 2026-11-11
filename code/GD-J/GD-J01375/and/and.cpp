#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m; 
int a[N];
int ton[N]; 
long long  ans;
void dfs(int u,int c){
	if(c==m or u==n+1 ){
		if(c==m){
			long long v=-1;
			for(int i=1;i<=u;i++){
				if(ton[i]==1){
					if(v==-1) v=a[i];
					else v=v||a[i];
				}
			}
			ans=max(ans,v);
		}
		return;	
	}
	ton[u]=1;
	dfs(u+1,c+1);
	ton[u]=0;
	dfs(u+1,c);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}

