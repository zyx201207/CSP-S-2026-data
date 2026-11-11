#include<bits/stdc++.h>
using namespace std;
//02 01A 03 01A
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}else{
		cout<<0;
	}
	string bs1,bs2;
	bs1+=s1[0],bs1+=s1[1],bs2+=s2[0],bs2+=s2[1];
	char zw1=s1[2],zw2=s2[2];
	if(bs1==bs2&&c1==c2){
		cout<<1;
	}else{
		cout<<0;
	}
	
	if((bs1!=bs2)||(((zw1=='F'||zw1=='D')&&(zw2=='A'||zw2=='B'||zw2=='C'))||((zw2=='F'||zw2=='D')&&(zw1=='A'||zw1=='B'||zw1=='C')))){
		cout<<0;
	}else{
		if(c1==c2){
			cout<<1;
		}else{
			cout<<0;
		}
	}
	
	if(bs1==bs2&&c1==c2&&abs(zw1-zw2)==1&&!((zw1=='D'&&zw2=='C')||(zw1=='C'&&zw2=='D'))){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
