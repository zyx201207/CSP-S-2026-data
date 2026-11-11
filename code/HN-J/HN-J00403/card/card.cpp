#include<bits/stdc++.h>
using namespace std;
long long n,m,a[250081],ans[250081],vis[250081],cnt[250081],last[250081],kvis[250081];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
		if(m==1){
			cout<<n;
			return 0;
		}
		for(long long k=1;k<=n;k++){
			memset(vis,0,sizeof(vis));
			memset(cnt,0,sizeof(cnt));
			memset(last,0,sizeof(last));
			memset(kvis,0,sizeof(kvis));
			for(long long i=k;i<=n;i++){
			if(vis[a[i]]==1){
				for(long long j=last[a[i]];j<i;j++){
					if(kvis[j]==0){
					cnt[a[j]]--;
					kvis[j]=1;	
					}
					vis[a[j]]=0;
				}
			}
			vis[a[i]]=1;
			last[a[i]]=i;
			cnt[a[i]]++;
		}
		for(long long i=1;i<=m;i++){;
			if(cnt[i]>=1){
				ans[i]++;
			}
		}
		}
		for(long long i=1;i<=m;i++){
			cout<<ans[i]<<' ';
		}
		return 0;
}
