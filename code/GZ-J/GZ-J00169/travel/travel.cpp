//GZ-J00169  遵义市第一初级中学 梁悠然 
#include <iostream>
using namespace std;
int main(){
   int x,y;
   string a,b;
   cin>>x>>a>>y>>b;
    if(x==y)	cout<<'1';
   else{
   	cout<<'0'<<'0'<<'0'<<'0';
   	return 0;
  }
   if(a[0]==b[0]&&a[1]==b[1])	cout<<'1';
   else{
   	cout<<'0'<<'0'<<'0';
   	return 0;
   }
   if(a[3]<='64' &&b[3]-a[3]<=2) cout<<'1';
   else{
   	if(a[3]=='D'&&b[3]=='F'){
   		cout<<'1';
	   }
    else{
   	cout<<'0'<<'0';
   	return 0;
   }
  }

   	if(b[3]-'1'==a[3]) cout<<'1';
   	else{
   		if(b[3]+'1'==a[3]) cout<<'1';
   	else cout<<'0';
   }
   	return 0;
   
}
