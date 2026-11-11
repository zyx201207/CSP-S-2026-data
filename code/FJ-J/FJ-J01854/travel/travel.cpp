#include<bits/stdc++.h>

using namespace std;
string c1,s1,c2,s2;
char a[15];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=1;i<=10;i++){
		cin>>a[i];
	}
	c1+=a[1],c1+=a[2];
	s1+=a[3],s1+=a[4];
	c2+=a[6],c2+=a[7];
	s2+=a[8],s2+=a[9];
	
	if(c1==c2){
		cout<<"1";
	}
	else{
		cout<<"0000";
		return 0;
	}
	if(s1==s2){
		cout<<"1";
	}
	else{
		cout<<"000";
		return 0;
	}
	if((a[5]>='A'&&a[5]<='C'&&a[10]>='A'&&a[10]<='C')
	||(a[5]>='D'&&a[5]<='F'&&a[10]>='D'&&a[10]<='F')){
		cout<<"11";
	}
	else{
		cout<<"00";
	}
	return 0;
}
