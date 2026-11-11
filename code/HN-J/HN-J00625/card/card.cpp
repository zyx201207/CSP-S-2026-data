#include <bits/stdc++.h>
using namespace std;
const int N=5E5+5,M=3E5+5;
int a[N],vis[M],z[N];
int n,m;
int main(){
	freopen("card.in","r",stdin);
	freopen ("card.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	for (int t=1;t<=n;t++){
		for (int i=1;i<=n-t+2;i++) z[i]=0; 
		int x=0,y=0;
		for (int i=t;i<=n;i++){
			bool q=1;
			for (int j=1;j<=y;j++){
				if (z[j]==a[i]){
					q=0;
					y=j;
					x=j;
					break;
				}
			}
			if (q==1){
				x++;
				y++;
				z[x]=a[i];
			}
		} 
		for (int i=1;i<=y;i++){
			vis[z[i]]++;
		}
	} 
	for (int i=1;i<=m;i++){
		cout<<vis[i]<<" ";
	}
	return 0;
} 
