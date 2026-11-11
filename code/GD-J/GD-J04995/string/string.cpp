#include<iostream>
#include<cstdio>
using namespace std;
int n ,num ,a[100] ;
int L=0;
string c[100] ,S[100];
int main(){
 freopen("string.in","r",stdin);
 freopen("string.out","w",stdout);
 cin >> n ;
 for (int i=1 ; i <= n ; i++){
 	cin >> a[i]>>c[i];
 	L += a[i];
 	for (int n=1;n<=a[i];n++ ){
 		S[n]=c[i];
	 }
 }
 
 
 
 cout << num;
 fclose(stdin);
 fclose(stdout);
	return 0;
}
