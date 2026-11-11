#include<bits/stdc++.h>                                              
using namespace std;
long long n[100000001];
int main(){
//freopen("card.in","r",stdin);
 //freopen("card.out","w",stdout);
   ios::sync_with_stdio(0);
   cin.tie(0);
   long long a,b;
   cin>>a>>b;
    int cnt=0;
   for(int i=1;i<=a;i++){
	   cin>>n[i];
	   for(int j=1;j<=a;j++){
		 if（n [j]==n[i]{
			 cnt++;
		 } 
		 
       }
       for(int j=i;j<=i;j++){
		   cnt++;
	   }
	   cout<<cnt;
  }
	      return 0;
}
