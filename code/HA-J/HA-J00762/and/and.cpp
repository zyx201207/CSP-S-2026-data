#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200010],n,m,ans;
void dfs(int c,int b,ll cnt,int tg){
	if(b==0){
		ans=max(ans,cnt);
		return;
	}if(c==0){
		return;
	}if(c!=tg){
		dfs(c-1,b-1,cnt&a[c],tg);
	}dfs(c-1,b,cnt,tg);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}for(int i=1;i<=n;i++){
		dfs(n,m-1,a[i],i);
	}cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
