#include <bits/stdc++.h>
using namespace std;		
int main() {
//freopen("trivel.in","r",stdin);
//freopen("trivel.out","w",stdout);

  string c1,s1,c2,s2;
  cin>>c1>>s1>>c2>>s2;
  if(c1==c2&&c2==c1){
  	cout<<"1";
  }else{
  	cout<<"0";
  }
 for(int i=0;i<=5;i++){
 	if(s1[i]>=s2[i]){
 		s1[i]=s2[i++];
 		cout<<"1";
	 }else if(s2[i]<=s1[i]){
	 	s2[i]=s1[i++];
	 	cout<<"0";
	 }
 }
 return 0;
}
