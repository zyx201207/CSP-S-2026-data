#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,a[N];
bool is[N][33],vis[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1,x;i<=n;i++){
		scanf("%d",&a[i]);
		x=a[i];
		for(int j=1;j<=31;j++) is[i][j]=x&1,x>>=1;
	}
	for(int i=31;i>=1;i--){
		int sum=0;
		for(int j=1;j<=n;j++) if(!vis[j]&&is[j][i]) ++sum;
		if(sum>=m) for(int j=1;j<=n;j++) if(!is[j][i]) vis[j]=1;
	}
	int ans=(1<<30)-1;
	for(int i=1;i<=n;i++) if(!vis[i]) ans&=a[i];
	printf("%d",ans);
	return 0;
}
