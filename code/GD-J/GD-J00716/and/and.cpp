#include<bits/stdc++.h>
using namespace std;
int as;
int n,m,a[10010];
void dfs(int x,int y,int sum){
	if(y==m){
		as=max(as,sum);
		return;
	}
	for(int i=x+1;i<=n;i++){
		dfs(i,y+1,a[i]&sum);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=20){
		dfs(1,1,a[1]);
		cout<<as;
	}
	else{
		if(m==1){
			int maxx=-10;
			for(int i=1;i<=n;i++){
				maxx=max(maxx,a[i]);
			}
			cout<<maxx;
		}else if(m==n){
			int k=a[1];
			for(int i=2;i<=n;i++){
				k&=a[i];
			}
			cout<<k;
		}
		else if(n==2){
			int maxx=-10;
			for(int i=1;i<=n;i++){
				for(int j=i;j<=n;j++){
					maxx=max(maxx,a[i]&a[j]);
				}
			}
			cout<<maxx;
		}
	}
	return 0;
} 
