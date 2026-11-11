#include<bits/stdc++.h>
using namespace std;
int n,m,ans[500005],a[500005],cnt[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(cnt[a[j]]!=0){
				cnt[a[j]]=0;
				for(int k=j-1;k>=i;k--){
					if(a[k]==a[j]) break;
					cnt[a[k]]=0;
				}
			} cnt[a[j]]++;
		}
		for(int j=1;j<=m;j++){
			if(cnt[j]>0) ans[j]+=1;
			cnt[j]=0;
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}
