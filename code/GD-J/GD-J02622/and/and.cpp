#include <bits/stdc++.h>
 using namespace std;
 int n,m,a[20005],ma=-1;
 int main ( ){
 	freopen ("and.in","r",stdin);
 	freopen ("and.out","w",stdout);
 	cin >>n>>m;
 	for (int i=1;i<=n;i++){
 		cin >>a[i];
	 }
	 if (m==2){
	 	for (int i=1;i<=n-1;i++){
	 		for (int j=i+1;j<=n;j++){
	 			if (a[i]|a[j]>ma){
	 				ma=a[i]|a[j];
				 }
			 }
		 }
		 cout <<ma;
	 }
	 else if (m==1){
	 	for (int i=1;i<=n;i++){
 		if (a[i]>ma){
 			ma=a[i];
		 }
	 }
	 cout <<ma;
	 }
 }
