#include<iostream>
#include<cstring>
using namespace std;
int a[500005];
int ans[300005];
int lst[300005];
bool vis[300005];
int n,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	bool is=0; 
	for(int i=1;i<=n;++i){
		cin>>a[i];
		if(i>1 && a[i]<a[i-1])is=1;
		lst[a[i]]=i;
	}
	if(is==0){
		for(int i=1;i<=m;++i){
			cout<<lst[i]<<' ';
		}
	}
	else{
		for(int i=1;i<=n;++i){
			memset(vis,0,sizeof(vis));
			for(int j=i;j<=n;){
				vis[a[j]]=1;
				if(lst[a[j]]!=j){
					j=lst[a[j]];
				}
				++j;
			}
			for(int j=1;j<=m;++j){
				if(vis[j]==1)++ans[j];
			}
		}
		for(int i=1;i<=m;++i){
			cout<<ans[i]<<' ';
		}
	}
	return 0;
} 
