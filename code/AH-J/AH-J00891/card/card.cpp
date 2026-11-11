#include<iostream>
#include<cstring>
using namespace std;
const int N=5e5+7,M=3e5+7;
int n,m;
int a[N],cnt[M];
int v[M];
bool vis[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(v,0,sizeof(v));
		memset(vis,0,sizeof(vis));
		for(int j=i;j<=n;j++){
			if(v[a[j]]==0) v[a[j]]=j;
			else{
				for(int k=v[a[j]];k<j;k++) v[a[k]]=0;
				v[a[j]]=j;
			}
		}
		for(int j=1;j<=n;j++){
			if(v[a[j]]!=0){
				if(!vis[a[j]]){
					cnt[a[j]]++;
					vis[a[j]]=1;
				}
			}
		}
	}
	for(int i=1;i<=m;i++) cout<<cnt[i]<<' ';
	return 0;
}
