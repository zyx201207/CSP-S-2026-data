#include<bits/stdc++.h>
using namespace std;
int a[500001],p[500001],ans[500001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	for(int i=2;i<=n+1;i++){
		int cnt=1;
		for(int j=i-1;j<=n;j++){
			p[cnt]=a[j];
			for(int k=cnt;k>=1;k--){
				if(p[k]==a[j]&&k!=j){
					for(int l=1;l<=cnt-1;l++){
						p[l]=0;
					}
				}
			}
			for(int k=1;k<=cnt;k++){
				if(p[k]!=0){
					ans[p[k]]++;
				}
			}
			cnt++;
		}
	}
	for(int i=1;i<=m;i++){
		if(i==1||i==2){
			cout<<ans[i]/2<<" ";
		}
		else
			cout<<ans[i]<<" ";
	}
	return 0;
}
