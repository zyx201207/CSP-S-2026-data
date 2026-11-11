#include<bits/stdc++.h>
using namespace std;

int a[500010];
int ans[500010];
int wei[500010][2];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(wei[a[i]][0]==0){
			wei[a[i]][0]=i;
		}
		wei[a[i]][1]=i;
	}
	
	for(int i=1;i<=n;i++){
		if(wei[a[i]][1]!=i){
			for(int j=1;j<=i;j++){
				ans[a[j]]++;
			}
			for(int j=n;j>=wei[a[i]][1]+1;j--){
				if(wei[a[j]][0]!=j&&wei[a[j]][0]>wei[a[i]][1]){
					for(int k=wei[a[i]][1]+1;k<=wei[a[j]][0];k++){
						ans[a[k]]++;
					}
					break;
				}
			}
			break;
		}
	}
	
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}


	return 0;
}
