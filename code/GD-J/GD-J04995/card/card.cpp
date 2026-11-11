#include<iostream>
#include<cstdio>
using namespace std;
int n, m ,num ,a[1000];
int main(){
 freopen("card.in","r",stdin);
 freopen("card.out","w",stdout);
 cin >> n >> m;
 for (int j=1;j<=n;j++){
 	cin >> a[j];
 }
 for (int k=n-1 ;k<=1;k--){
 	
 	if(a[n]==a[k]){
 		
 		
 		num=a[k]  ;
	 }
 }
 for (int x=1;x<=m;x++){
 	cout << num;
 }
 fclose(stdin);
 fclose(stdout);
	return 0;
}
