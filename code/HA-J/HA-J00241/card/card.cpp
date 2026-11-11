#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],num,ans[300005],l[300005];
int v[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int k=i;k<=n;k++){
			for(int j=1;j<=num;j++){
				if(v[j]==a[k]){
					for(int l=j;l<=num;l++)v[l]=0;
					num=j;
				}
			}
			v[++num]=a[k];
		}
		for(int j=1;j<=n;j++){
			l[v[j]]=1;
		}
		for(int j=1;j<=m;j++){
			ans[v[j]]+=l[v[j]];
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
