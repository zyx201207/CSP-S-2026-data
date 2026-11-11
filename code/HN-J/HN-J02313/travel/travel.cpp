#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a1,a2,b1,b2,a4,b4;
	char a3,b3;
	cin>>a1>>a2>>a3>>b1>>b2>>b3;
	a4=a3;b4=b3;
	if(a1==b1)cout<<1;
	else{
	cout<<"0000";
	return 0;}
	if(a2==b2)cout<<1;
	else{
	cout<<"000";
	return 0;}
	if((a4<=67&&b4<=67)||(a4>=68&&b4>=68)){
	cout<<1;}
	else{
	cout<<"00";
	return 0;}
	if(((a4!=65&&b4!=66)||(a4!=66&&b4!=65))&&((a4+1==b4)||(b4+1==a4))){
	cout<<1;
	}
	else cout<<0;
	return 0;
}

