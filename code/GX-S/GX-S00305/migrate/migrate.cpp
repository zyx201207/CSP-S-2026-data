#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,inf=0x3f3f3f3f;
int c,t;
int n,d;
int a[N];
int xi,xj;
int ll=1,sum=inf,ans;
int vis1[N],vis2[N];
int tjh;
void dfs(int x){
	if(x>n-1){
		for (int i=1;i<n;i++){
			if(vis1[i]){
				if(a[i+1]-a[i]>=d) vis2[i+1]=1;
					ll++;
			}
		}
		if(ll<sum){
			tjh++;
			sum=ll;
		}
		else if(ll==sum){
			tjh++;
		}
		ll=0;
		return;
	}
	vis1[x]=1;
	dfs(x+1);
	vis1[x]=0;
	dfs(x+1);
}
int main () {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >>c >>t;
	while(t--){
		cin >>n >>d;
		for (int i=1;i<=n;i++){
			cin >>a[i];
		}
		for(int i=1;i<=n;i++){
			for (int j=i;j<=n;j++){
				xi=i;
				xj=j;
				vis1[xi]=1;
				vis2[xi]=1;
				dfs(xi);
				if(tjh>=2) ans++;
			}
			ll=1;
			for (int j=1;j<=n;j++){
				vis1[j]=0;
				vis2[j]=0;
			}
		}
		cout <<ans <<endl;
		ans=0;
	}
	
	return 0;
}
