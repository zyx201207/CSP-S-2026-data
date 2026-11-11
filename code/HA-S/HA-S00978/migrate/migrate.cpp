#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,ci,sum,ans;
int a[2000005],b[2000005];
void dfs(int x,int y,int k){
	if(k>ci){
		return ;
	}
	if(x==y){
		if(k<ci){
			ci=k;
			sum=1;
		}
		else if(k==ci){
			sum++;
		}
		return ;
	}
	for(int i=min(b[x],y);a[i]-a[x]<=d && i>x;i--){
		dfs(i,y,k+1);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		ans=0;
		for(int i=1;i<n;i++){
			int x=i;
			while(a[x+1]-a[i]<=d && x+1<=n){
				x++;
			}
			b[i]=x;
		}
		for(int i=1;i<=n-3;i++){
			for(int j=i+3;j<=n;j++){
				ci=1e9;
				sum=0;
				dfs(i,j,0);
				if(sum==2){
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
} 
