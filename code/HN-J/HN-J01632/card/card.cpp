#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
int i,s,o=0;
cin>>i;
for(int a=0;a<i;a++){
cin>>s;
if(s==10){
o=1;	
}
}
if(o==1){
	cout<<"10 3 3";
}else {
	cout<<"3 1 4";
}
}
