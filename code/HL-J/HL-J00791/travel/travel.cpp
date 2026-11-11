#include<bits/stdc++.h>
using namespace std;
int main(){
//freopen("travel.in","r",stdin);
//freopen("travel.out","w",stdout);
string a,b,c,d,e,f;char g,k;
cin>>a>>b>>c>>d;
if(a==c){
	cout<<"1";
}
else{
	cout<<"0000";return 0;
}
for(int i=0;i<=1;i++){
	e+=b[i];
	f+=d[i];
}
g=b[2];
k=d[2];
if(e==f){
	cout<<"1";
}
else{
	cout<<"000";return 0;
}
if((g>='D'&&k>='D')||(g<'D'&&k<'D')){
	cout<<1;
}else{
	cout<<"00";return 0;
}if(g+1==k||k+1==g){
	cout<<"1";
}
else{
	cout<<"0";
}
return 0;
}




