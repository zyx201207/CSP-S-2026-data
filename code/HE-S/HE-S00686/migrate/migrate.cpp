#include<bits/stdc++.h>
using namespace std;
const int N = 2e6+10;
int c,t,n,d;
int a[N],minn[N],tot[N];
void dfs(int x,int ans){
	if(minn[x]>ans){
		minn[x] = ans;
		tot[x] = 1;
	}
	else if(minn[x]==ans){
		tot[x]++;
	}
	for(int i = x+1;i<=n;i++){
		if(a[i]-a[x]<=d){
			dfs(i,ans+1);
		}
		else{
			break;
		}
	}
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i = 1;i<=n;i++){
			cin>>a[i];
			minn[i] = i-1;
			tot[i] = 0;
		}
		int ans = 0;
		for(int i = 1;i<=n;i++){
			memset(minn,0x3f,sizeof(minn));
			memset(tot,0,sizeof(tot));
			dfs(i,0);
			for(int j = i;j<=n;j++){
				if(tot[j]==2){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
