#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],bt[200010][50],cnt[1010],vis[200010],ans;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int xx=a[i];
		for(int j=30;j>=0;j--){
			if(xx>=(1<<j)){
				bt[i][j]=1;
				cnt[j]++;
				xx-=(1<<j);
			}
		}
	}
	for(int i=30;i>=0;i--){
		if(cnt[i]<m)continue;
		for(int j=1;j<=n;j++){
			if(!bt[j][i]&&!vis[j]){
				vis[j]=1;
				for(int k=0;k<=30;k++){
					cnt[k]-=bt[j][k];
				}
			}
		}
		ans+=(1<<i);
//		cout<<i<<" "<<cnt[i]<<'\n';
	}
	cout<<ans;
}
