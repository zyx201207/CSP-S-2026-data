#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int n,m,a[N],b[M][2],c[M]={},vis[50];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i+=1){
		cin>>a[i];
	}
	for (int i=1;i<=n;i+=1){
		memset(b,0,sizeof b);
		memset(vis,0,sizeof vis);
		for (int j=i;j<=n;j+=1){
			b[a[j]][0]+=1;
			vis[j]=1;
			if (b[a[j]][0]==2){
				for (int k=b[a[j]][1];k<j;k+=1){
					b[a[k]][0]-=vis[k];
					vis[k]=0;
				}
			}
			b[a[j]][1]=j;
		}
		for (int j=1;j<=m;j+=1){
			if (b[j][0]==1){
				c[j]+=1;
			}
		}
	}
	for (int i=1;i<=m;i+=1){
		cout<<c[i]<<" ";
	}
	return 0;
}
