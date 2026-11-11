#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int n,m;
long long mp[N];
long long num=1;
int dfs(int ans,int x,int a){
	if(a==m) return ans;
	if(n+a-x+1==m){
		int aa=ans;
		for(int i=x;i<=n;i++) aa=aa&mp[i];
		return aa;
	}
	return max(dfs(ans&mp[x],x+1,a+1),dfs(ans,x+1,a));
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>mp[i];
	if(m==1){
		long long maxn=-1;
		for(int i=1;i<=n;i++) maxn=max(maxn,mp[i]);
		cout<<maxn;
	}else if(m==n){
		for(int i=1;i<=n;i++){
			num=num & mp[i];
		}
		cout<<num;
	}else{
		int maxn=-1;
		for(int i=1;i<=n-m+1;i++){
			maxn=max(maxn,dfs(mp[i],i,0));
		}
		cout<<maxn;
	}
	return 0;
}

