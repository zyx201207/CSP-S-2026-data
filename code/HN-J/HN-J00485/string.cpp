#include <bits/stdc++.h> 
#include <iostream> 
using namespace std;
typedef long long ll;
//ios::

int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
int ii=0,n,a=0,a2,a3,a4,a5,a6;
ll op;
char c=0,c2,c3,c4,c5,c6=0;
cin>>ii;
for (int i=1;i<=ii;i++){

	
	cin>>n>>c;

	if(a!=c){
op+=n;
	}
	a=c; 
}
/*if (ii<=2){
op=5;
}
*/
cout<<op;
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
return 0;

 /*6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b 
*/

}
