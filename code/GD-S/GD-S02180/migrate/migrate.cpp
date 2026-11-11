#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,x[2000010]={0},l[2000010]={0},ans=0,dl[2000010];
void dfs(int left){
	if(left==n)return;
	for(int i=left+1;l[i]<=d&&i<=n;i++){
		dl[i]++;
		dfs(i);
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			l[i]=x[i]+x[i-1];
			dl[i]=0;
		}
		for(int i=1;i<=n;i++){
			dfs(i);
			if(dl[i]==2)ans++;
		}
	}
	cout<<ans;
	return 0; 
}
