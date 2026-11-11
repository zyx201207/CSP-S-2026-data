#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500010],x[300010],nx[500010],v[300010],s[300010],vis[500010];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=n;i>=1;i--){
		if(!x[a[i]]) x[a[i]]=i;
		nx[i]=x[a[i]];
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		int x=0;
		memset(v,0,sizeof(v));
		for(int j=i;j<=n;j=nx[j]+1){
			x+=1-vis[j];
			s[a[j]]+=x-v[a[j]];
			v[a[j]]=x;
			vis[j]=1;
		}
	}
	for(int i=1;i<=m;i++) cout<<s[i]<<" ";
	return 0;
}
