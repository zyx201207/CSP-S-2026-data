#include<bits/stdc++.h>
using namespace std;
int a[5000000];
int b[3000000];
int c[5000000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	int x=0,y=0,z=0,abc;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		abc=i;
		z=0;
		x=0;
		for(int j=1;j<=n;j++){
			c[j]=a[j];
		}
		for(int j=i;j<=n-x;j++){
			y=j;
			for(int q=i;q<j;q++){
				if(c[q]==c[j]){
					x+=q-i;
					for(int ee=q;ee<=n;ee++){
						if(y<=n){
							c[ee]=c[y];
							y++;
						}else{
							c[ee]=0;
						}if(y==n){
							z=ee;
						}
					}	
				}
				break;
		 	}
		}
		for(int j=1;j<=z;j++){
			b[c[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
} 
