#include<bits/stdc++.h>
#define int long long
using namespace std;

const int maxn=2e5+7;
int a[maxn],cnt[maxn],n,d;

void dfs(int x,int y,int s,int last){
	if(x==y){
		if(last==a[y])cnt[s]++;
		return;
	}
	dfs(x+1,y,s,last);
	if(a[x+1]-last<=d){
		dfs(x+1,y,s+1,a[x+1]);
	}
	else return;
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				memset(cnt,0,sizeof cnt);
				dfs(i,j,0,a[i]);
				int res=0;
				for(int k=1;k<=j-i+1;k++){
					if(cnt[k]){
						res=cnt[k];
						break;
					}
				}
				if(res==2)ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
