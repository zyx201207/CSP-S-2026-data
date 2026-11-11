#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int h[n];
	for(int i=0;i<n;i++) cin>>h[i];
	int lp[n];
	int cnt[m];
	memset(cnt,0,sizeof(cnt));
	for(int i=1;i<=n;i++){
		int jiesuo=-1;
		for(int j=i-1;j<=n;j++){
			for(int l=0;l<=n;l++){
				if(lp[l]==h[j-1]){
					for(int l1=jiesuo;l1>=l;l1--){
						lp[jiesuo]=0;
						jiesuo--;
					}
				}
			}
			lp[jiesuo]=h[j-1];
			jiesuo++;
		}
		for(int j=1;j<=m;j++){
			for(int l=0;l<=jiesuo;l++){
				if(lp[l]==j){
					cnt[j]++;
					break;
			}
		}
	}
	}
	for(int i=0;i<n;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}
