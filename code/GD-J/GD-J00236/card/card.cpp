#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int fa[500005];
int l[500005];
int ans[300005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	memset(fa,0,sizeof(fa));
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(fa[a[i]]==0){
			fa[a[i]]=i;
		}else{
			l[fa[a[i]]]=i;
			fa[a[i]]=i;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(l[j]==0){
				ans[a[j]]++;
			}else{
				ans[a[j]]++;
				while(l[j]!=0)j=l[j]; 
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
} 
