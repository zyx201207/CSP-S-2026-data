#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
int n,m;
int a[N];
int vis[N];
int best[N];
int vv[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int minn=1e18;
	for(int i=n;i>=1;i--){
		if(vis[a[i]]==0){
			best[a[i]]=i;
		}
		vis[a[i]]++;
		vv[i]=best[a[i]];
		int bb=vv[i]+1;
		int kk[300010];
		for(int j=i;j<=bb-2;j++){
			if(kk[a[i]]==0){
			 	vis[a[i]]--;
			 	kk[a[i]]=1;
			}
		}
		int kkk[300010];
		for(int j=bb;j<=n;j++){
			if(kkk[a[i]]==0){
				vis[a[i]]++;
				kkk[a[i]]=1;
			}
		}
		best[a[i]]=i;
	}
	for(int i=1;i<=m;i++){
		cout<<vis[i]<<' ';
	}
	return 0;
}


