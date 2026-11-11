#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e6+5;
bool flag[MAXN];
int a[MAXN],k,sum,d,n;
void dfs(int x,int p,int r){
	if(p>k)return ;
	if(x==r){
		sum++;
		if(p<k){
			k=p;
			sum=1;
		}
		return ;
	}
	for(int i=x+1;i<=x+d;i++)dfs(i,p+1,r);
}
void solve(){
	scanf("%d %d",&n,&d);
	
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			k=n+1,sum=0;
			dfs(i,0,j);
			if(sum==2)ans++;
		}
	}
	printf("%d\n",ans);
	return ;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	scanf("%d %d",&c,&t);
	while(t--)solve();
	return 0;
}
