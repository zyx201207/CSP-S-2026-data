#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int sum[300005];
int vis[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=n;j>=i;j--){
			if(!vis[a[j]]){
				vis[a[j]]=j;
				sum[a[j]]++;
			}
			else{
				for(int k=j+1;k<vis[a[j]];k++){
					sum[a[k]]--;
				}
				break;
			}
		}
		for(int j=n;j>=i;j--){
			vis[a[j]]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<sum[i]<<" ";
	}
	return 0;
}
