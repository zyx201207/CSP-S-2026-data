#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
using namespace std;
int n ,m ,t,num[100] ,a[100];
int b = 0;
int main(){
 freopen("and.in","r",stdin);
 freopen("and.out","w",stdout);
 cin >> n >> m ;
 for (int i=1;i<=n;i++){
 	cin >> a[i] ;
 }
 for(int j=1 ;j<=n;j++){
 	for(int k=j+1;k<=n;k++){
 		num[j] = (  a[j] &&  a[k]);
 		t += 1;
		 }
	 }
for (int x=1;x<=t;x++){
	if(num[x]> b){
		b = num[x];
	}
cout << b;
  fclose(stdin);
  fclose(stdout);
	return 0; 
}
}
