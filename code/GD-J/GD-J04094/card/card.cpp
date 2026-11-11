#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int n,m,a[500005],mc[300005];
int vis[300005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		vis[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;){
			if(vis[a[j]]!=j){
				j=vis[a[j]];
				continue;
			}
			mc[a[j]]++;
			j++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<mc[i]<<' ';
	}
	return 0;
}

