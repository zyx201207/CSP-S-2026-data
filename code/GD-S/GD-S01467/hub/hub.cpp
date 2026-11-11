#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,k,ans;bool v[N],jz[N];
vector<int>G[N];
void ltk(int x){
	v[x]=1;
	for(int y:G[x])if(!v[y]&&jz[y])ltk(y);
}
bool check(){
	int cnt=0;
	for(int i=1;i<=n;i++)v[i]=0;
	for(int i=1;i<=n;i++)if(!v[i]&&jz[i]){cnt++;ltk(i);}
	return (cnt<=2);
}
int get(int x,int xfa){
	if(jz[x])return 0;
	int res=n+1;
	for(int y:G[x])if(y!=xfa)res=min(res,get(y,x)+1); 
	return res;
}
void dfs(int pos,int sum){
	if(pos==n+1){
		if(check()){
			int sum=0;
			for(int i=1;i<=n;i++)sum=max(sum,get(i,0));
			ans=min(ans,sum);
			return;
		}
	}
	if(n-pos>=k-sum){
		jz[pos]=0;
		dfs(pos+1,sum);
	}
	if(sum<k){
		jz[pos]=1;
		dfs(pos+1,sum+1);
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%d",&n,&k);ans=n+1;
		for(int i=1;i<=n;i++)G[i].clear(),v[i]=jz[i]=0;
		for(int i=1;i<n;i++){
			int x,y;scanf("%d%d",&x,&y);
			G[x].push_back(y);
			G[y].push_back(x);
		}
		dfs(1,0);
		printf("%d\n",ans);
	}
	return 0;
}
