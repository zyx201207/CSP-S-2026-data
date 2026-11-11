#include<iostream>
#include<cstring>
using namespace std;
int a[200005],ans[100005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		bool vis[100005];
		memset(vis,false,sizeof(vis));
		for(int j=i;j<=n;j++){
			if(!vis[a[j]]){
				ans[a[j]]++;
				vis[a[j]]=true;
			}
		}
	}
	for(int i=1;i<=k;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
