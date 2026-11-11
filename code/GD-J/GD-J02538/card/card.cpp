#include<bits/stdc++.h>
using namespace std;
int n,m,c[500005];
int ans[300005],cnt[300005];
int lst[300005];
int li[300005],ct;
int he[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	bool flag=1;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(li[c[i]]==0) {li[c[i]]=++ct;he[ct]=c[i];}
		c[i]=li[c[i]];
	}
	for(int i=1;i<=n;i++){
		if(i!=1&&c[i]<c[i-1]){
			flag=0;
		}
		lst[c[i]]=i;
		cnt[c[i]]++;
	}
	if(flag){
		for(int i=1;i<=m;i++){
			ans[i]=lst[i];
		}
	} else {
		for(int i=1;i<=m;i++){
			if(cnt[i]==0) continue;
			int lt=0;
			for(int j=lst[i];j<=n;j=lst[c[j]]+1){
				cnt[c[j]]+=cnt[lt];
				cnt[lt]=0;
				ans[c[j]]+=cnt[c[j]];
				lt=c[j];
			}
			cnt[lt]=0;
		}
	}
	for(int i=1;i<=m;i++) {
		cnt[he[i]]=ans[i];
	}
	for(int i=1;i<=m;i++) {
		cout<<cnt[i]<<' ';
	}
	return 0;
}
