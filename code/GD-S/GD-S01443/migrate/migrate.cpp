#include<bits/stdc++.h>
using namespace std;
#define int long long 
int a[2000010],meme[2000010];
int dfs(int n,int d){
	if(n<=2){
		return meme[n]=0;
	}
	if(meme[n]){
		return meme[n];
	}
	int cnt=1;
	for(int i=n-1;i>=n-d&&i>=1;i--){
		meme[n]+=dfs(i,d);
	}
	return meme[n];
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,t;
	scanf("%lld%lld",&c,&t);
	while(t--){
		int n,d;
		memset(a,0,sizeof(a));
		scanf("%lld%lld",&n,d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		
		scanf("%lld\n",dfs(n,d));
	}
}
