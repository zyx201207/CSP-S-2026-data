//观山湖中学 刘郅铖 GZ-J00274
#include<bits/stdc++.h>
using namespace std;
	
	int n,m,ans[300001];
	int a[300001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
	cin>>a[i];
	}	int cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int k=j;k<=n;k++){
				if(a[j]==a[k]){
					cnt++;
					ans[cnt]=a[k];
				}
				if(k==n){
					cnt++;
					ans[cnt]=a[k];
				}
			}
		}
	}
	for(int j=1;j<=m;j++){
			cout<<ans[j]<<' '; 
		}
}
