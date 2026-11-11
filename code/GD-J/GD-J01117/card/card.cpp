#include <bits/stdc++.h>
using namespace std;
int a[500005];
int p[500005];
int cnt[300005];
int vis[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	for(int i=1;i<=n;i++){
		memset(p,0,sizeof(p));
		memset(vis,0,sizeof(vis));
		for(int j=i;j<=n;j++){
			//cnt[a[j]]++;
			bool f=0;
			for(int k=max(vis[a[j]],i);k<=j-1;k++){
				if(f){
					cnt[p[k]]--;
					p[k]=-1;
					continue;
				}
				if(p[k]==a[j]){
					//cout<<p[k]<<" "<<a[j]<<"\n";
					f=1;
					cnt[p[k]]--;
					p[k]=-1;
				}
			}
			p[j]=a[j];
			cnt[a[j]]++;
			if(!vis[a[j]])vis[a[j]]=j;
		}
	}
	for(int i=1;i<=m-1;i++){
		cout<<cnt[i]<<" ";
	}
	cout<<cnt[m];
	return 0;
}
