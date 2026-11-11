#include<bits/stdc++.h>
using namespace std;
long long n,m;
int y[200005],w[200005],maxx=-1e9;
void dfs(int t,int k){
	if(k==m){
		int u=0,h=0;
		for(int i=1;i<=n;i++){
			if(y[i]==1){
				if(u==0){
					u=1;
					h=w[i];
				}else{
					h=(h)&(w[i]);
				}	
			}
		}
//		for(int i=1;i<=10;i++){
//			cout<<y[i];
//		}
//		cout<<endl;
		maxx=max(maxx,h);
	}else if(t<=n){
		y[t]=1;
		dfs(t+1,k+1);
		y[t]=0;
		dfs(t+1,k);
		y[t]=0;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>w[i];
	}
	dfs(1,0);
	cout<<maxx;
	return 0;
}
