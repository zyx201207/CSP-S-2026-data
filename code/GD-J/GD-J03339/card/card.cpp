#include<bits/stdc++.h>
using namespace std;
int ans[300005],n,m,a[500005],i,int u[500005];
int main(){
	freopen("card.in","r",stdin);freopen("card.in","r",stdin);
	cin>>n>>m;
	for(i=1;i<=n;i++)cin>>a[i];
	if(n<1000){
		for(i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				u[j]=a[j];
				for(int k=j-1;k>=i;k--){
					if(u[k]==a[j]){
						for(int o=k;u[o]!=0;o--){
							u[o]==0;
						}
					}	
				}
			}
			for(int j=1;j<n;j++){
				if(u[j]!=0)ans[a[i]]+=j;
			}
		}
		
	}
	for(i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			if(a[i]==a[j]&&a[i]==0&&a[j]==0){
				u[i]=j;u[j]=-i;
			}
		}
	}
	int k=0;
	for(i=1;i<=n;i++){
		if(u[i]==0)ans[i]+=k;
		else if(u[i]<0){
			ans[i]+=k;k
		}
	}
	for(i=1;i<=m;i++)cout<<ans[i];
}
