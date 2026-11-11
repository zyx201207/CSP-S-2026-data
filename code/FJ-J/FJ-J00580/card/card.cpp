#include<bits/stdc++.h>
using namespace std;
int a[500005],b[300005],bi=0,c[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int m,n;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		bi=0;
		for(int j=i;j<=n;j++){
			for(int k=1;k<=bi;k++){
				if(b[k]==a[j]){
					bi=k-1;
					break;
				}
			}
			b[++bi]=a[j];
			
		}
		for(int k=1;k<=bi;k++){
			for(int d=1;d<=m;d++){
				if(b[k]==d)c[d]++;
			}
		}
	}
	for(int i=1;i<=m;i++)cout<<c[i]<<' ';
	return 0; 
}
