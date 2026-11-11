#include<bits/stdc++.h>
#define int long long
#define pr pair<int,int>
using namespace std;
const int N=5e5+5,M=3e5+5;
int n,m;
int a[N];
bool vis[N];
int ans[M],last[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int start=1;start<=n;start++){
		memset(vis,0,sizeof(vis));
		for(int i=0;i<start;i++)
			vis[i]=true;
		for(int i=start;i<=n;i++){
			if(!vis[last[a[i]]]){
				for(int j=last[a[i]]+1;j<i;j++)
					vis[j]=true;
			}
			last[a[i]]=i;
		}
		for(int i=1;i<=m;i++)
		  if(!vis[last[i]]) ans[i]++;
	}
	for(int i=1;i<=m;i++)
	  cout<<ans[i]<<" ";
	return 0;
}
/*
4 3
1 2 1 3
10 3
3 1 2 1 3 2 3 1 2 1
*/
