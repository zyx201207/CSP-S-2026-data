#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		int x[500005];
		for(int j=1;j<=n;j++) x[j]=a[j];
		for(int j=i;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				if(x[j]==x[k]){
					for(int l=j;l<k;l++) x[l]=0;
					break;
				}
			}
		}
		for(int j=i;j<=n;j++) b[x[j]]++;
	}
	for(int i=1;i<=m;i++) cout<<b[i]<<" ";
	return 0;
}

