#include<bits/stdc++.h>
using namespace std;
struct st{
	int last,num;
} a[500010];
long long m,n,laast[300010],vis[300010],ans[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i].num;
		a[i].last=laast[a[i].num];
		laast[a[i].num]=i;
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<=m;j++) vis[j]=0;
		for(int j=i;j<=n;j++){
			if(vis[j]==0) vis[j]=1;
			else{
				for(int k=a[j].last+1;k<j&&k>=i;k++){
					vis[a[k].num]=0;
				}
			}
		}
		for(int j=1;j<=m;j++){
			if(vis[j]==1) ans[j]++;
		}
	}
	for(int i=1;i<=m;i++) cout << ans[i];
	return 0;
}
