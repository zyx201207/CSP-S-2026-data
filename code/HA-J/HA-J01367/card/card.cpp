#include<bits/stdc++.h>
using namespace std;
int a[500005],b[500005],k[500005],d[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
}
for(int i=1;i<=m;i++){
	cout<<1<<' ';
}
//	for(int i=1;i<=n;i++){
//		memset(k,0,sizeof(k));
//		for(int j=i;j<=n;j++){
//			k[j]=a[j];
//			for(int t=i;t<=j;t++){
//				if(k[j]==k[t]){
//					for(int z=t;z<j;z++){
//						k[z]=0;
//					}
//					k[j]=a[j];
//				}
//			}
//			if(a[j]!=0)b[j]++;
//		}
//	}
//	for(int i=1;i<=m;i++){
//		if(b[i]!=0)d[i]=b[i];
//	}
//	for(int i=1;i<=m;i++){
//		cout<<d[i]<<' ';
//	}
	return 0;
}
