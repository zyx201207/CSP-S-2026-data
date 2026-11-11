#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],cut,sum=1,ans,vis[200005];
long long ss(long long n){
	long long a=1,cut=0;
	while(a*2<=n)a*=2,cut++;
	return cut;
}
void dfs(long long cut,long long sum){
	if(cut<0)return ;
	long long k=0;
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		if(a[i]%(sum*2)/sum==1)k++;
	}
	if(k>=m){
		ans+=sum;
		for(int i=1;i<=n;i++){
			if(a[i]%(sum*2)/sum==0){
				vis[i]=1;
			}
		}
		dfs(cut-1,sum/2);
		return ;
	}else{
		dfs(cut-1,sum/2);
	}
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cut=max(ss(a[i]),cut);
	}
	for(int i=1;i<=cut;i++)sum*=2;
	dfs(cut,sum);
	cout<<ans;
	return 0;
}
