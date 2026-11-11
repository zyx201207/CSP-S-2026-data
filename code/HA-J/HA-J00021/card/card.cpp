#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=5e5+5,M=3e5+5;
int n,m,a[N],pre1[N],d[N],nxt[N],ans[M],f[N];

signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	memset(pre1,-1,sizeof pre1);
	memset(f,0,sizeof f);
	for(int i=n;i>0;i--){
		nxt[i]=pre1[a[i]];
		if(pre1[a[i]]==-1)pre1[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		if(f[i]==1)continue;
		int p=i,cs=1;
		while(p<=n){
			for(;nxt[p]!=-1;p=nxt[p]){
				
				d[p++]+=cs;
			}
			if(f[p]==0)cs++;
			d[p++]+=cs;
			if(p<n)f[p]=1;
		} 
		ans[a[i]]=max(ans[a[i]],d[i]);
	}
	ans[a[n]]=n;
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}

