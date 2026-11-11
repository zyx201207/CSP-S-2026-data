#include<bits/stdc++.h>
using namespace std;
long long n,m,k1,k2;//选m,n个数字 
vector<long long>k;
vector<bool>vis;
long long dfs(long long nownum,long long nowtwc,long long ans){//dfs边界先写
	long long maxx=-1e9; //最大层与最大,在里面与 
	long long as=ans&k[nowtwc];
	if(nownum==m){return as;
	}
	
	for(long long i=0;i<n;i++){
		if(vis[i])continue;
		vis[i]=true;
		maxx=max(maxx,dfs(nownum+1,i,as));
		vis[i]=false;
	}return maxx;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld %lld",&n,&m);//选n恰好m
	long long mx=-1e9;
	bool pf=false;
	for(long long i=1;i<=n;i++){
		scanf("%lld",&k1);
		if(pf==false){
			if(k1!=i-1)pf=true;
		}
		mx=max(mx,k1);
		k.push_back(k1);
		vis.push_back(false);
	}
	if(m==1){
		cout<<mx;
		return 0;
	}
	if(pf==false){
		cout<<n;
		return 0;
	}
	for(long long i=0;i<n;i++){vis[i]=true;
	k2=max(k2,dfs(1,i,k[i]));
	vis[i]=false;}
	printf("%lld",k2);
}
