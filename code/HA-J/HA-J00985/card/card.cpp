#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],q[500005],r,ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int flag=0;
	for(int i=1;i<=n;i++){
		if(a[i]<a[i-1]){
			flag=1;
			break;
		}
	}
	if(flag){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=r;j++){
				q[i]=0;
			}
			r=0;
			for(int j=i;j<=n;j++){
				for(int k=1;k<=r;k++){
					if(q[k]==a[j]){
						while(r>=k) q[r--]=0;
					}
				}
				q[++r]=a[j];
			}
			for(int j=1;j<=r;j++){
				ans[q[j]]++;
			}
		}	
		for(int i=1;i<=m;i++){
			cout<<ans[i]<<" ";
		}
	}else{
		for(int i=1;i<=n;i++){
			for(int j=1;j<=r;j++){
				q[i]=0;
			}
			r=0;
			for(int j=i;j<=n;j++){
				for(int k=r;k>=1;k--){
					if(q[k]<a[j]){
						break;
					}
					q[r--]=0;
				}
				q[++r]=a[j];
			}
			for(int j=1;j<=r;j++){
				ans[q[j]]++;
			}
		}	
		for(int i=1;i<=m;i++){
			cout<<ans[i]<<" ";
		}
	}
	return 0;
} 
