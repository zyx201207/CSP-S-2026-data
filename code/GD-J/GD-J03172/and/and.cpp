#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m,a[int(2e5+10)],mx,res[int(2e5+10)],x;
void dfs(int x,int r){
	if(x>n&&r==m){
		ll cnt=0;
		for(int i=1;i<=n;i++){
			if(res[i]==1){
				if(cnt==0) cnt=a[i];
				else cnt&=a[i];
			}
		}
		mx=max(mx,cnt);
		return;
	}
	else if(x>n&&r!=m) return;
	dfs(x+1,r);
	res[x]=1;
	dfs(x+1,r+1);
	res[x]=0;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,0);
	cout<<mx;
	return 0;
}
