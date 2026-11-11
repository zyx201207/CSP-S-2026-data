#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000000],b[1000000],c[1000000],d[1000000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
    for(int i=1;i<=n;i++){
		cin>>a[i];
	}
    for(int i=1;i<=n;i++){
    	for(int j=i;j<=n;j++){
    	 if(b[j]==0){
			b[j]=1;
			c[j]=a[j];
		 }
		 else{
		   for(int l=b[a[j]];l<=j;l++){
		   	   c[l]=0;
		   	   b[l]=0;
		   }	
    	}			
	}
	for(int l=i;l<=n;l++){
		d[c[l]]++;	   
	}
}
for(int i=1;i<=m;i++){
	cout<<d[i]<<" ";
}
}
