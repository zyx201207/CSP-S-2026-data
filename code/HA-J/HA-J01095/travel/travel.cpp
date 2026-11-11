#include<bits/stdc++.h>
using namespace std;int a,b,c,d;char x,y;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
cin>>a>>b>>x>>c>>d>>y;
if(a==c){
cout<<1;
}else{
	cout<<0;
}
if(b==d&&a==c){
	cout<<1;
}else{
	cout<<0;
}
if(x=='A'&&y=='B'||x=='B'&&y=='C'||x=='A'&&y=='C'||x=='D'&&y=='F'||y=='A'&&x=='B'||y=='B'&&x=='C'||y=='A'&&x=='C'||y=='D'&&x=='F'){
	cout<<1;
}else{
	cout<<0;
}
if(x=='A'&&y=='B'||x=='B'&&y=='C'||x=='D'&&y=='F'||y=='A'&&x=='B'||y=='B'&&x=='C'||y=='D'&&x=='F'){
	cout<<1;
}else{
	cout<<0;
}
return 0;
} 
