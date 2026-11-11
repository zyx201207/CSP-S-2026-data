#include <bits/stdc++.h>
using namespace std;
int c,t;
long long zd=LONG_MAX;
long long js;
bool f[50005];
long long a[2000005];
long long n,d;
void dfs(int x,int y,long long cnt,long long num){
	if(x==y){
		if(cnt==zd) js++;
		if(cnt<zd){
			js=1;
			zd=cnt;
		}
	}
	for(int i=x+1;i<=num;i++){
		if(x!=i&&f[i]==0&&d>=abs(a[i]-a[x])){
			f[i]=1;
			dfs(i,y,cnt+1,num);
			f[i]=0;
		}
	}
	return ;
}
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		long long ans=0;
		cin>>n>>d;
		a[n+5]={0};
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				zd=LONG_MAX;
				js=0;
				if(i!=j){
					dfs(i,j,0,n);
					if(js==2) ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
