#include<iostream>
#include<vector>
#include<string.h>
#include<queue>
using namespace std;
const int N=2e6+1;
long long c,t,a[N],f[15][15];
vector<long long> ans[15][15];
void dfs(int x,int n,int s,int d){
	for(int i=x+1;i<=n;i++){
		if(f[s][i]>f[s][x]+a[i]-a[x]&&a[i]-a[x]<=d){
			f[s][i]=f[s][x]+a[i]-a[x];
			//cout<<x<<" ";
			ans[s][i].push_back(f[s][i]);
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		long long n,d;
		cin>>n>>d;
		for(long long i=1;i<=n;i++) cin>>a[i];
		memset(f,0x3f,sizeof f);
		for(int i=1;i<=n;i++) f[i][i]=0;
		for(int i=1;i<=n;i++){
			dfs(i,n,i,d);
		}
		int sum=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				int cnt=0;
				for(int k=0;k<ans[i][j].size();k++){
					if(ans[i][j][k]==f[i][j]) cnt++;
				}
				if(cnt==2) sum++;
			}
		}
		cout<<sum<<"\n";
	}
	return 0;
}
