#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],cnt[300005],ans[300005],x;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		x=i;
		for(int j=i;j<=n;j++){
			cnt[a[j]]++;
			if(cnt[a[j]]==2){
				for(int l=x;l<j;l++){
					cnt[a[l]]--;
				}
				x=j;
			}
		}
		for(int j=1;j<=m;j++){
			if(cnt[j]==1)
				ans[j]++;
			cnt[j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
