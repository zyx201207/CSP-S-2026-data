#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,a[N],ans[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			bool vis[N];
			if(vis[a[i]]){
				for(int k=1;k<=n;k++){
					ans[k]=0;
					vis[k]=0;
				}
			}
			vis[a[j]]=1;
			ans[a[j]]++;
		}
	}
	for(int i=1;i<=n;i++){
		if(ans[i]==0)continue;
		cout<<ans[i]<<" ";
	}
	return 0;
}
