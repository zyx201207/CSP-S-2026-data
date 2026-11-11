#include<bits/stdc++.h>
using namespace std;
const int g=100055;
long long a[5*g],b[3*g],c[3*g],n,m,vis[3*g];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(vis[a[i]]!=0){
			c[vis[a[i]]]=i;
		}
		c[i]=i+1;
		vis[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			vis[j]=0;
		}
		for(int j=i;j<=n;j=c[j]){
			if(vis[a[j]]==0){
				b[a[j]]++;
				vis[a[j]]=1;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
