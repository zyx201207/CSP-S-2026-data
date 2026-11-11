#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[1000001],ans[1000001],qc[1000001];
int bj[1000001],f[1000001],fa[1000001];

signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		f[a[i]]=i;
	}
	for(int i=1;i<=n;i++)fa[i]=f[a[i]]+1;
	for(int i=1;i<=n;i++){
		if(qc[i]==1) continue;
		int x=i,y=0;
		while(x<=n){
			if(qc[x]==0)qc[x]=1,y++;
			if(bj[a[x]]!=i) ans[a[x]]+=y,bj[a[x]]=i;
			x=fa[x];
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
} 
