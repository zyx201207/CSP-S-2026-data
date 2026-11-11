#include<bits/stdc++.h>
using namespace std;
int b[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,s=0;
	cin>>n>>m;
	int a[n+5],c[n+5];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			c[j]=0;
			s=0;
			for(int k=1;k<=j;k++){
				if(s==1){
					c[k]=0;
				}
				if(c[k]==a[j]){
					s=1;
					c[k]=0;
				}
			}
			c[j]=a[j];
		}
		for(int j=1;j<=m;j++){
			for(int k=1;k<=n-i;k++){
				if(c[k]==j){
					b[j]=b[j]+1;
					break;
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
