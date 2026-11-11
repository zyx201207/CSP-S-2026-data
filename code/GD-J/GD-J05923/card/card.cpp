#include<bits/stdc++.h>
using namespace std;
int n,m,a[200020],ans[200010],pd[200010],A=1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(A==1){
			if(a[i]>=a[i-1]){				
			}
			else{
				A=0;
			}
		}
	}
	if(A==0){
		for(int k=1;k<=n;k++){
			for(int i=k;i<=n;i++){
				for(int j=1;j<=i-1;j++){
					if(pd[j]==a[i]){
						for(int o=j;o<=i-1;o++){
							pd[o]=0;
						}
						break;
					}
				}
				pd[i]=a[i];
			}
			for(int i=1;i<=n;i++){
				ans[pd[i]]++;
			}
			for(int i=1;i<=n;i++){
				pd[i]=0;
			}
		}
		for(int i=1;i<=m;i++){
			cout<<ans[i]<<" ";
		}
	}
	else{
		for(int k=1;k<=n;k++){
			ans[a[k]]=k;
		}
		for(int i=1;i<=m;i++){
			cout<<ans[i]<<" ";
		}
	}
	return 0;
}
