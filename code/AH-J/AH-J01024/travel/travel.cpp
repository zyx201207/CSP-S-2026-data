#include<bits/stdc++.h>
using namespace std;
string a,pa,b,pb;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>pa>>b>>pb;
	if(a==b)cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	if(pa[0]==pb[0]&&pa[1]==pb[1]){
		cout<<1;
	}
	else {
		cout<<"000";
		return 0;
	}
	if((pa[2]>='A'&&pa[2]<='C'&&pb[2]>='A'&&pb[2]<='C')||(pa[2]>='D'&&pa[2]<='F'&&pb[2]>='D'&&pb[2]<='F')){
		cout<<1;
	}
	else{
		cout<<"00";
		return 0;
	}
	if((abs((int)pa[2]-(int)pb[2])==1)||(pa[2]=='D'&&pb[2]=='F')||(pa[2]=='F'&&pb[2]=='D')){
		cout<<1;
	}
	else cout<<0;
	return 0;
} 
