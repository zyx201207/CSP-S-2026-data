#include"bits/stdc++.h"
using namespace std;
#define LL long long
const int N=5e3+5;
int c,t;

int n,d;

int a[N];

int dp[N];

int maxs;

int ls(int i,int j){
	LL s=1;
	int k=upper_bound(a+i+1,a+n+1,i+d)-a-1;
	while (k<j){
		i=k;
		k=upper_bound(a+i+1,a+n+1,i+d)-a-1;
		s++;
	}
	return s;
}
void dfs(int i,int j,int s,int k){
	if (s>maxs) return ;
	if (k==j) dp[j]++;
	for (int ii=1;ii<=d;ii++){
		if (ii+k<=j) dfs(i,j,s+1,ii+k);
	}
}
int main(){
	freopen ("migrate.in","r",stdin);
	freopen ("migrate.out","w",stdout);
	scanf ("%d%d",&c,&t);
	while (t>0){
		LL ans=0;
		t--;
		scanf ("%d%d",&n,&d);
		for (int i=1;i<=n;i++) {
			scanf ("%d",&a[i]);
		}
		for (int i=1;i<=n;i++){
			for (int j=i+1;j<=n;j++){
				memset(dp,0,sizeof(dp));
				maxs=ls(i,j);
				dfs(i,j,0,i);
				for (int k=i;k<=j;k++){
					if (dp[k]==2) ans++;
				}
			}
		}
		printf ("%lld\n",ans);
	}
	return 0; 
}
