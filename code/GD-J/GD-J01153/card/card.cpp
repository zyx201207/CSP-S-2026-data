#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m;
int a[N],sum[N],b[N],ans[N],st[N],ed[N],cnt;
bool vis[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(vis[a[i]]==0){
			st[a[i]]=i;
			vis[a[i]]=1;
		}else{
			ed[a[i]]=i;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(ed[a[j]]!=0)j=ed[a[j]];
			b[++cnt]=a[j];
		}
	}
	for(int i=1;i<=cnt;i++){
		ans[b[i]]++;
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}

