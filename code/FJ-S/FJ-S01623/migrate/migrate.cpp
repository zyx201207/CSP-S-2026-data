#include<bits/stdc++.h>
using namespace std;
long long table[305][305];
long long small[305][305];
long long island[305];
long long n,d;
void dfs(long long from,long long at,long long v,long long m){
	if(at==v){
		if(m<small[from][v]){
			small[from][v]=m;
			table[from][v]=1;
		}
		else if(m==small[from][v]){
			table[from][v]++;
		}
		return;
	}
    if(m>=small[from][v])return;
	for(int i=v;i>=at+1;i--){
		if(island[i]-island[at]<=d)dfs(from,i,v,m+1);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	long long c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		if(n<=15){
			for(int i=0;i<305;i++){
				for(int j=0;j<305;j++){
					table[i][j]=0;
					small[i][j]=0x3f3f3f3f3f3f3f3f;
				}
				island[i]=0;
			}
			for(int i=1;i<=n;i++)cin>>island[i];
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					dfs(i,i,j,0);
				}
			}
			long long ans=0;
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(table[i][j]==2){
						ans++;
					}
				}
			}
			cout<<ans<<'\n';
		}
		else cout<<0<<'\n';
	}
	return 0;
}
