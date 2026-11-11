#include<bits/stdc++.h>
using namespace std;
int r,x;
string q,y;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
cin>>r>>q>>x>>y;
if(r==x){
	cout<<1;
}else{
	cout<<0;
}
if(q[0]==y[0] and q[1]==y[1]){
	cout<<1;
}else{
	cout<<0;
}
cout<<0 or 1;
cout<<0 or 1;
return 0;
}