#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[5100],c[5100],l[5100],aa[5100],ans[5100];
void dfs(ll cur){
	if(cur>n){
		for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
		return ;
	}
	memset(c,0,sizeof c);
	memset(l,0,sizeof l);
	//memset(aa,0,sizeof aa);
	ll t=0;
	for(int i=cur;i<=n;i++){
		if(l[a[i]]==0){
			c[++t]=a[i];
			l[a[i]]=t;
		}
		else{
			for(int j=l[a[i]]+1;j<=t;j++){
				l[c[j]]=0;
				c[j]=0;
			}
			t=l[a[i]];
		}
	}
	for(int i=1;i<=t;i++){
		ans[c[i]]++;
	}
	dfs(cur+1);
	return ;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1);
	return 0;
}
