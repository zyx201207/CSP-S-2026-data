#include<bits/stdc++.h>
using namespace std;
int n,m,a[5010];
int cnt[50005][3010];
int last[5005];
int ne[5005];
int ans[3005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(last[a[i]]!=0){
			ne[last[a[i]]]=i;
		}
		last[a[i]]=i;
	}
	
	ans[a[n]]=1;
	cnt[n][a[n]]=1;
	for(int i=n-1;i>=1;i--){
		if(ne[i]==0){
			for(int j=1;j<=m;j++){
				ans[j]+=cnt[i+1][j];
				cnt[i][j]=cnt[i+1][j];
			}
			ans[a[i]]+=1;
			cnt[i][a[i]]+=1;
		}else{
			for(int j=1;j<=m;j++){
				ans[j]+=cnt[ne[i]][j];
				cnt[i][j]=cnt[ne[i]][j];
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
