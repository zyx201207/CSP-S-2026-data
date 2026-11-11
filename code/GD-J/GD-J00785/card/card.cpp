#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans[200005],cnt[5005][3005],cnt1[5005][3005],cnt2[200005][5],cnt3[200005][5];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<2e5){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++) cnt[i][j]=0,cnt1[i][j]=0;
		}for(int i=1;i<=n;i++){
			cnt[i][a[i]]++,cnt1[i][a[i]]++;
			for(int j=1;j<=m;j++) cnt[i][j]+=cnt[i-1][j];
		}for(int i=n;i>=1;i--){
			for(int j=1;j<=m;j++) cnt1[i][j]+=cnt1[i+1][j];
		}for(int k=1;k<=m;k++){
			for(int i=1;i<=n;i++){
				bool flag=1;
				for(int j=i;j<=m;j++){
					if(j==a[i]){
						if(!cnt1[i][j]) ans[k]++;
						continue;
					}if(cnt1[i][j] && cnt[i][j]%2==1) flag=0;
				}if(flag) ans[k]++;
			}
		}for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	}else{
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++) cnt2[i][j]=0,cnt3[i][j]=0;
		}for(int i=1;i<=n;i++){
			cnt2[i][a[i]]++,cnt3[i][a[i]]++;
			for(int j=1;j<=m;j++) cnt2[i][j]+=cnt2[i-1][j];
		}for(int i=n;i>=1;i--){
			for(int j=1;j<=m;j++) cnt3[i][j]+=cnt3[i+1][j];
		}for(int k=1;k<=m;k++){
			for(int i=1;i<=n;i++){
				bool flag=1;
				for(int j=i;j<=m;j++){
					if(j==a[i]){
						if(!cnt1[i][j]) ans[k]++;
						continue;
					}if(cnt1[i][j] && cnt[i][j]%2==1) flag=0;
				}if(flag) ans[k]++;
			}
		}for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
