#include <bits/stdc++.h> 
//#include <iostream> 
using namespace std;
typedef long long ll;
//ios::

int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
 int c1=91,c3=78;
 float c2=0,c4=0,a=1000;
 cin>>c1>>c2>>c3>>c4;
	 
 	if(c1==c3){
 		a=1000;
	 }

	 if(c2!=c4){
 		a=1111;
	 }
    
//cout<<c1<<' '<<c2<<' '<<c3<<' '<<c4<<' '<<a<<endl;
cout<<a;

 return 0;
}
