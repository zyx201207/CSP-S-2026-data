#include<iostream>
using namespace std;
int n,m;
int a[500005],vis[500005],cmp[500005],ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
		for(int i=1;i<=n;i++){
			if(vis[a[i]]!=0){
				for(int j=cmp[a[i]];j<i;j++){
					vis[a[j]]--,cmp[a[j]]=0;
				}
			}
			vis[a[i]]++,cmp[a[i]]=i;
		}
	for(int i=1;i<=m;i++) cout<<vis[i]<<' ';
	return 0;
}
