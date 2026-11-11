#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int c,t,n;
ll d;
ll a[5005];
int dfs(int x,int y,int p){
	if(x==y) return p;
	int sum=p;
	for(int k=x+1;k<=n;k++){
		if(abs(a[x]-a[k])<=d) sum+=dfs(k,y,p);
		else break;
	}
	return sum;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		int ans=0;
		for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) if(dfs(i,j,0)==2) ans++;
		cout<<ans<<'\n';
	}
	return 0;
}
