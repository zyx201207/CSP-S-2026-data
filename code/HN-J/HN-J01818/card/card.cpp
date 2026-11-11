#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int b[500005];
int ans[300005];
bool vis[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
            if(!vis[a[j]]){
			    ans[a[j]]++;
				vis[a[j]]=true;			         	
			}
			else{
				for(int k=j-1;a[k]!=a[j];k--){
					ans[a[k]]--;
					a[k]=0;
				}
			}
		}
		for(int j=1;j<=n;j++){
			vis[j]=false;
			a[j]=b[j];
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
