#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],maxn[500005],minn[500005],vis[5000005];
int ans[300005],q[500005],h=0,t=1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn[a[i]]=max(maxn[a[i]],i);
		minn[a[i]]=n+1;
	}
	for(int i=1;i<=n;i++){
		while(t<=h){
			if(maxn[a[q[h]]]<=i||a[i]==a[q[h]]){
				h--;
				continue;
			}
			vis[i]=q[h];
			break;
		}
		if(maxn[a[i]]!=i) q[++h]=i;
	}
	for(int i=n;i>=1;i--){
		if(minn[a[i]]>i){
			ans[a[i]]+=i-vis[i];
			minn[a[i]]=vis[i];
		}
		else if(vis[i]<minn[a[i]]){
			ans[a[i]]+=minn[a[i]]-vis[i];
			minn[a[i]]=vis[i];
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
