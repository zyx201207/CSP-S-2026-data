#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,d=0;
	cin>>n>>m;
	int a[n];
	int d1[m];
	for(int k=1;k<=m;k++){
		d1[k]=0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int b[n];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n-i+1;j++){
			b[j]=a[i+j-1];
			int c=0;
			for(int k=1;k<=j;k++){
				if(c==1){
					b[k]=0;
				}
				if(b[k]==b[j]){
					c=1;
				}
			}
		}
		for(int j=1;j<=n-i+1;j++){
			for(int k=1;k<=m;k++){
				if(b[j]==k){
				d1[k]+=1;	
				}
			}
		}
	}
	for(int k=1;k<=m;k++){
		cout<<d1[k]<<" ";
	}	
	return 0;
}
