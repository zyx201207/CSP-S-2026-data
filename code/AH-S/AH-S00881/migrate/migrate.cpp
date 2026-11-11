#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int C,t,n,x[305][305],minn[305][305];
ll a[2000005],d;
void dfs(int rt,int c,int from){ //rt c from 
	if(c==minn[from][rt]) {
		x[from][rt]++;
	}
	for(int i=rt+1;i<=n;++i){
		if(a[i]-a[rt]>d) break;
		//cout<<rt<<' '<<c<<' '<<from<<'\n';
		dfs(i,c+1,from);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>C>>t;
	while(t--){
		int ans=0;
		cin>>n>>d;
		if(n<=300){
		memset(minn,-1,sizeof(minn));
		memset(x,0,sizeof(x));
		for(int i=1;i<=n;++i){
			cin>>a[i];
		}
		ll tmp;
		for(int cnt,i=1;i<=n;i++){
			for(int j=i+1;j<=n;++j){
				tmp=d,cnt=1;
				for(int k=i;k<j;++k){
					if(a[k+1]-a[k]>tmp) {
						++cnt;
						tmp=d;
					}else{
						tmp-=a[k+1]-a[k];
					}
				}
				minn[i][j]=cnt;
				//cout<<i<<' '<<j<<' '<<minn[i][j]<<'\n';
			}
		}
		for(int i=1;i<n;++i){
			dfs(i,0,i);
		}
		for(int i=1;i<n;++i){
			for(int j=i+1;j<=n;++j){
				ans+=(x[i][j]==2);
			}
		}
		cout<<ans<<'\n';
		}else{
			for(int i=1;i<=n;++i){
				cin>>a[i];
			}
			ll k=a[2]-a[1];
			ll m=d/k;
			if(m<=1||2*m-1>=n) cout<<0<<'\n';
			else cout<<n-2*m+1<<'\n';
		}
	}
	return 0;
}
