#include<bits/stdc++.h>
using namespace std;
long long a[10000],o=0,mx=0;
void dfs(int n,int m,int x,int k){
	if(n==m&&k==mx){
		o++;
		
		return;
	}else if(n==m&&k>mx){
		mx=k;
		o=1;
		return;
	}
	for(int i=n+1;i<=m;i++){
		if(a[i]<=a[n]+x){
			dfs(n+1,m,x,k+1);
		}else{
			return;
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long n,m,c,t;
	cin>>c>>t;
	while(t--){
		o=0;
		int p=0;
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				o=0;
				mx=0;
				if(j==i){
					continue;
				}
				dfs(i,j,m,0);
				if(o==2){
					p++;
				}
			}
		}
		cout<<p<<endl;
	}
	
	return 0;
} 
