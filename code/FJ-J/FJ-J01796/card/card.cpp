#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500100],vis[300100],ans[300100];
int g[500100];
int st[500100];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	int s=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n-1;i++){
		if(a[i]>a[i+1]){
			s=1;
		}
	}
	if(s==0){
		for(int i=n;i>=1;i--){
			g[a[i]]=i;
		}
		for(int i=1;i<=m;i++){
			cout<<n-g[i]+1<<" ";
		}
		return 0;
	}else{
		int v=0;
		for(int i=n;i>=1;i--){
			if(vis[a[i]]==1){
				int vi=v;
				for(int j=vi;j>=1;j--){
					if(st[j]!=a[i]){
						v--;
						vis[st[j]]=0;
						st[j]=0;
					}else{
						break;
					}
				}
				for(int j=v;j>=1;j--){
					ans[st[j]]++;
				}
			}else{
				vis[a[i]]=1;
				st[++v]=a[i];
				for(int j=1;j<=v;j++){
					ans[st[j]]++;
				}
			}
		}
		for(int i=1;i<=m;i++){
			cout<<ans[i]<<" "; 
		}
	}
		
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/ 
