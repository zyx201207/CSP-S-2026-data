//GZ-J00397 张颜淏 贵阳市云岩区中天中学 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10;
ll n,m,a[N],ans=0;
void dfs(ll k,ll li,ll cnt){
	if(cnt<=ans)return;
	if(k==m+1){
		ans=max(ans,cnt);
		return;
	}
	
	for(ll i=li+1;i<=n;i++){
		if((cnt&a[i])>=ans){
			dfs(k+1,i,cnt&a[i]);
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	for(int i=1;i<=n;i++)dfs(2,i,a[i]);
	cout<<ans;
	return 0;
}
