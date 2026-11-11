#include <bits/stdc++.h>
using namespace std;
int n,m;
int ans;
int a[200005],cnt[200005][40],sum[40];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int k=1<<30,j=1;
		while(k){
			if(a[i]>=k){
				cnt[i][j]=1;
				sum[j]++;
				a[i]-=k;
			}
			j++;
			k/=2;
		}
	}
	int k=1<<30;
	for(int i=1;i<=31;i++){
		if(sum[i]>=m){
			ans+=k;
			for(int j=1;j<=n;j++){
				if(cnt[j][i]==0){
					for(int l=1;l<=31;l++){
						if(cnt[j][l]==1){
							sum[l]--;
							cnt[j][l]=0;
						}
					}
				}
			}
		}
		k/=2;
	}
	cout<<ans;
	return 0;
}
