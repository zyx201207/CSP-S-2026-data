//GZ-J00501 ¸ß´ï 
#include<bits/stdc++.h>
using namespace std;
int n , m ;
const int N=1e7+10;
int a[N];
int main(){
	freopen("and.in" , "r" , stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m ;
	for(int i = 1 ; i<= n ; i++){
		cin >> a[i];	
}

 sort(a+1,a+n+1);
 for(int i = 1 ; i<= n ; i++){
 		 if(n%2==0){
		  cout <<min(a[n/2],a[n/2+1]);
		  return 0 ;
		  
 	}
 	else{
 		 cout << a[n/2+1];	
 		 return 0 ;
 }
}
	return 0 ;
}
