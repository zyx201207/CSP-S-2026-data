#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
	freopen("card.in1","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+5],lp[m+5],cnt[m+5];
	for(int i=1;i<=m+5;i++){
		lp[i]=0;
		cnt[i]=0;
	}
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		lp[a[i]]=i;
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<m;j++){
			int h=0;
			for(int k=i;k<=n;k++){
				if(a[k]==j){
					h=k;
					break;
				}
			}
			if(lp[j]>=i){
				for(int k=h-1;k>=i;k--){
					for(int l=lp[j];l<=n;l++){
						if(a[k]==a[l]){
							goto b;
						}
					}
				}
				cnt[j]++;
			}
			b:
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<' ';
	}
	return 0;
}
