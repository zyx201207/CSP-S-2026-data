#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005];
long long maxx=-1;
void dfs(long long id,long long s,long long k){
	if(n-id+s<m){
		return;
	}
	if(s==m){
		maxx=max(maxx,k);
		return;
	}
	if(k==0){
		dfs(id+1,s+1,a[id+1]);
		dfs(id+1,s,0);
	}else{
		dfs(id+1,s+1,k&a[id+1]);
		dfs(id+1,s,k);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	long long l=-1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		l=max(l,a[i]);
	}
	if(n>20 && n<=2000){
		if(m==1){
			cout<<l;
			return 0;
		}
		if(m==n){
			long long q=a[1];
			for(int i=2;i<=n;i++){
				q&=a[i];
			}
			cout<<q;
			return 0;
		}
		if(m==2){
			long long g=-1;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(i!=j){
						long long y=a[i]&a[j];
						g=max(g,y);
					}
				}
			}
			cout<<g;
			return 0;
		}
	}
	dfs(1,1,a[1]);
	dfs(1,0,0);
	cout<<maxx;
	return 0;
}
