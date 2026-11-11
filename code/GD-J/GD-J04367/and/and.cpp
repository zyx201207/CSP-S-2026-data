#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[200005];
int vis[200005];
struct node{
	int zhi,w;
}q[200005];
bool cmp(node x,node y){
	return x.zhi>y.zhi;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	int mx=0,cur=0,ans=-1;
	for(int i=1;i<=n;i++){
		cin>>a[i];mx=max(mx,a[i]);
	}
	if(m==1){
		cout<<mx<<"\n";
		return 0;
	}
	for(int i=30;i>=0;i--){
		if(m<2)break;
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(a[j]>>i&1){
				cnt++;
			}
		}
		if(cnt>=2){
			for(int j=1;j<=n;j++){
				if(a[j]>>i&1){
					vis[j]+=(1ll<<i);
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		q[++cur].zhi=vis[i];
		q[cur].w=a[i];
	}
	sort(q+1,q+1+cur,cmp);
	for(int i=1;i<=m;i++){
		if(ans!=-1)ans=ans&q[i].w;
		else ans=q[i].w;
	}
	cout<<ans<<"\n";
	return 0;
}
