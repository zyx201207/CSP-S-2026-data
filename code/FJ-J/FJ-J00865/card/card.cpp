#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,sum=0;
int a[300010],ans[300010],b[300010];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	while(sum<=n){
		sum++;
		for(int i=sum;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(b[j]==a[i]){
					b[j]=a[i];
					for(int z=j+1;z<=n;z++){
						b[z]=0;
					}
				}else b[j]=a[i];
			}
		}
		for(int i=1;i<=m;i++){
			ans[b[i]++];
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
