#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5007;
int c,t;
int n,d,ans;
int a[N];
int cnt[N][N],minn[N][N];
void dfs(int l,int sta,int s){
	//cout<<l<<" ";
	if(s<minn[sta][l]){
		minn[sta][l]=s,cnt[sta][l]=1;
	}
	else if(s==minn[sta][l]) cnt[sta][l]++;
	for(int i=l+1; i<=n; i++){
		if(a[i]-a[l]<=d) dfs(i,sta,s+1);
		else break;
	}
	return ;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1; i<=n; i++) cin>>a[i];
		ans=0;
		for(int i=1; i<=n; i++){
			for(int j=i; j<=n; j++){
				minn[i][j]=1e9;
				cnt[i][j]=0;
			}
		}
		for(int i=1; i<=n; i++){
			dfs(i,i,0);
			//cout<<"[ ";
		}
		for(int i=1; i<=n; i++){
			for(int j=i; j<=n; j++){
				if(cnt[i][j]==2) ans++;
				//cout<<cnt[i][j];
			}
			//cout<<endl;
		}
		cout<<ans<<endl;
	}
	return 0;
}
