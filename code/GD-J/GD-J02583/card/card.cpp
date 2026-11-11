#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500005],xb[300005],ans[300005];
bool cnt[300005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(xb[a[j]]!=0){
				int kk=xb[a[j]];
				for(int k=j-1;k>=kk;k--){
					xb[a[k]]=0;
					cnt[a[k]]=0;
				}
				xb[a[j]]=j;
				cnt[a[j]]=1;
			}else{
				xb[a[j]]=j;
				cnt[a[j]]=1;
			}
		}
		for(int j=1;j<=m;j++){
			if(cnt[j]!=0) ans[j]++;
			xb[j]=0,cnt[j]=0;
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
