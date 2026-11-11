#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,ans=-1;
int a[N],vis[N];
void name(int now,int k){
	if(k==m){
		ans=max(ans,now);
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			name(now&a[i],k+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		vis[i]=1;
		name(a[i],1);
		vis[i]=0;
	}
	cout<<ans;
	return 0;
}
