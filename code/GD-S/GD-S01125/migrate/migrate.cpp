#include<bits/stdc++.h>
using namespace std;
int c,t;
long long a[2000010];
int f[5050][5050];

long long n,d;
void dfs(int p,int c,int start){
	if(p>=n) return;
	if(c>=1) f[start][p]++;
	for(int i=1;i<=d;i++){
		dfs(p+i,c+1,start);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		long long ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n-2;i++){
			dfs(i,0,i);
		}
		
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(f[i][j]==2) {
					ans++;
					cout<<i<<" "<<j<<endl;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
