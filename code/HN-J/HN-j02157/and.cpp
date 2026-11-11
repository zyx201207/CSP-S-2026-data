#include<bits/stdc++.h> 
using namespace std;
int main(){
//freopen("and.in","r",stdin);
//freopen("and.out","w",stdout);
int m,n,a[20005],b[20005][100],c=0;
cin>>m>>n;
for(int i=0;i<m;i++){
	cin>>a[i];
}
for(int i=0;i<m;i++){
	c=0
	while(1){
		b[i][c]=a[i]%2;
		a[i]=a[i]/2;
		c++;
		if(a[i]==0){
			b[i][c+1]=c;
			break;
		}
	}
}c=0;
for(int i=0;i<m;i++){
	while(1){
		c++
		if(b[i][c]!=1&&b[i][c!=0]){
			for(int j=0;j<c;j++){
				
			}
		}
	}
}
	return 0; 
}
