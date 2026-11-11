#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int cx[3],cy[3],x,y;
	string sx,sy;
		cin>>cx[1];
		for(int i=1;i<=3;i++)
	cin>>sx[i];
		cin>>cy[1];
		for(int i=1;i<=3;i++)
	cin>>sy[i];
	int z;
		if(cx[1]!=cy[1]){
		cout<<0<<0<<0<<0;
		z=0;
		return 0;}
	else
	z=1;
	if(z==1)
	cout<<1;
	for(int i=1;i<=2;i++){
		if(sx[i]!=sy[i]){
		cout<<0<<0<<0;
		z=0;
		return 0;
	}
	else
	z=1;
	}
	if(z==1)
	cout<<1;
	x=sx[3]-'A';
	y=sy[3]-'A';	
	if(x>2&&y>2)
	{
	cout<<1;
	z=0;
}
if(x<2&&y<2)
	{
	cout<<1;
	z=0;
}
if(z==1){
cout<<0<<0;
return 0;
}
if(x-y==1){
z=1;
cout<<1;}
if(y-x==1){
z=1;
cout<<1;
}
if(z==0)
cout<<0<<" ";

	return 0;
}

