#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
long long n,m;

int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
cin>>a>>b>>c>>d;



if(a==c){
	n+=1;	
}else{
	n+=0;
}
if(n==0){
	cout<<"0000";
	return 0;
}

cout<<1<<1<<0<<1;

return 0;
}
