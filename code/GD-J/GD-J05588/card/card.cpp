#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int a[500005],s1[500005],cnt[300005],vis[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	bool f=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1]){
			f=0;
		}
	}
	if(f=1){
		for(int i=1;i<=m;i++){
			cout<<i<<" ";
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		int t=0;
		memset(vis,0,sizeof(vis));
		for(int j=i;j<=n;j++){
			if(vis[a[j]]==0){
				s1[++t]=a[j];
				vis[a[j]]=t;
			}
			else{
				for(int k=vis[a[j]]+1;k<=t;k++){
					vis[s1[k]]=0;
				}
				t=vis[a[j]];
			}
		}
		for(int j=1;j<=t;j++){
			cnt[s1[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}
