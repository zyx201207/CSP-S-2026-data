#include<bits/stdc++.h>
#include<string>
using namespace std;
const int N=1e7;
int n,m,a[N],c[N],f=0,b[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		c[i]=a[i];
	}
	int p=n;
	for(int i=1;i<=p;i++){
		f=0;
		for(int j=i;j<=p;j++){
			a[j]=c[j];
		}
		for(int j=i;j<=p;j++){
			for(int k=j-1;k>=i;k--){
				if(a[j]==a[k]&&k!=j&&a[j]!=0){
					a[k]=a[j];
					for(int l=k+1;l<=j;l++) a[l]=0;
				}
				
			}
		}
		//for(int j=i;j<=p;j++) cout<<a[j]<<" ";
		for(int j=i;j<=p;j++){
			for(int l=1;l<=m;l++){
				if(a[j]==l){
					b[l]++;
				}
			}
		}
	}
	for(int i=1;i<=m;i++) cout<<b[i]<<" ";
	return 0;
} 
