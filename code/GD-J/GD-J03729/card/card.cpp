#include <bits/stdc++.h>
using namespace std;
int a[500005],q[500005],ans[500005];
int vis[500005],num[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int l=1,r=0;
		memset(vis,0,sizeof(vis));
		memset(num,0,sizeof(num));
		for(int j=i;j<=n;j++){
			for(int k=l;k<=r;k++){
				if(q[k]==a[j]){
					r=k-1;
					for(int l=1;l<=m;l++){
						if(num[l]>=k){
							num[l]=0;
							vis[l]=0;
						}
					}
					break;
				}
			}
			r++;
			q[r]=a[j];
			vis[a[j]]=1;
			num[a[j]]=r;
		}
		for(int j=1;j<=m;j++){
			if(vis[j]){
				ans[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<' ';
	return 0;
}
