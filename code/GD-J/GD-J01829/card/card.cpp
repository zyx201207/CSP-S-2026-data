#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],cnt[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		bool tbv[50005]={};
		int tb[500005]={},tbl=0;
		for(int j=i;j<=n;j++){
			tb[++tbl]=a[j];
			if(tbv[a[j]]){
				int l=tbl;
				for(int c=tbl;c>0;c--){
					if(tb[c]==a[j]&&c!=l) break;
					tbl--;
					tbv[tb[c]]=0;
				}
			}
			tbv[a[j]]=1;
		}
		for(int i=1;i<=n;i++){
			if(tbv[i]) cnt[i]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}
