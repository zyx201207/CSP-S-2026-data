#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+7;
int n,m,a[N],b[N],ans[N];
int vis[N]; 
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int T=1;
	while(T<=n){
		int len=0;
		memset(vis,0,sizeof(vis));
		memset(b,0,sizeof(b));
		for(int i=T;i<=n;i++){
			if(vis[a[i]]==0) vis[a[i]]=len+1,b[++len]=a[i];
			else{
				for(int k=vis[a[i]];k<=len;k++)
					b[k]=0;
				len=vis[a[i]],b[len]=a[i];
			}
		} 
		for(int i=1;i<=len;i++){
			ans[b[i]]++;
		}T++;
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<' ';
	return 0;
}
/*
4 3
1 2 1 3
10 3
3 1 2 1 3 2 3 1 2 1
*/
