#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];int b[15];
int find(int x,int y){
	for(int i=1;i<=x;i++){
		if(a[i]==y)return i;
	}
	return x+1;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
 	cin>>n>>m;
 	for(int i=1;i<=n;i++){
 		cin>>a[i];
 	}
 	for(int i=1;i<=1;i++){
 		
 		for(int j=i;j<=n;j++){
 			int k=find(j,a[j]);
 			int t=k;
 			while(b[t]==0){
 				b[t]=0;
 				t++;
 			}
 			b[k]=a[j];
 		}
 		for(int i=1;i<=n;i++){
 		cout <<b[i];
 	}
 		
 	}
 	
	return 0;
}
