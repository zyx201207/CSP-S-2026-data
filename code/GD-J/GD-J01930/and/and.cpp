#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[2000500],vis[2000500];
long long ant;
void dp(int id,long long ans){
	if(id==m+1){
		ant=max(ant,ans);
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			if(id==1){
				ans=a[i];
			}else{
				ans=ans&a[i];
			}
			vis[i]=1;
			dp(id+1,ans);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dp(1,0);
	cout<<ant;
	return 0;
}
