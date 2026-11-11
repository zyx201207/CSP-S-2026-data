#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5,S=1e5+5;
int a[N],ans[S];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
   	ios::sync_with_stdio(0);cin.tie(0);
	int n,m;cin>>n>>m;
	//for(int i=1;i<=m;i++)ans[i]=n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int vis[S],shan[S];
		for(int x=1;x<=n;x++){
			vis[x]=0,shan[x]=0;
		}
		for(int j=i;j<=n;j++){
			if(vis[a[j]]){
				for(int k=vis[a[i]];k<=j;k++)vis[k]=0;
			}
			vis[a[j]]=i;
		}
		for(int x=1;x<=n;x++){
			if(vis[x])ans[a[x]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' '; 
	}
} 


