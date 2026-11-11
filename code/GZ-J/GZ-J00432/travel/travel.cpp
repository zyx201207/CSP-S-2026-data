//GZ-J00432 贵阳市第三十四中学 杨宗泽 
#include<bits/stdc++.h>
char a[8],b[8],c[10],d[10];
int xa,xb,xc,xd; 
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    cin>>a>>c>>b>>d;
    xa=(a[0]-'0')*10+(a[1]-'0');
    xb=(b[0]-'0')*10+(b[1]-'0');
    if(xa==xb){
    	cout<<1;
	}
    else{
    	cout<<"0000";
    	return 0;
	}
    xc=(c[0]-'0')*10+(c[1]-'0');
    xd=(d[0]-'0')*10+(d[1]-'0');
    if(xc==xd){
        cout<<1;
	}
	else{
		cout<<"000";
		return 0;
	}
	if((c[2]=='D'&&d[2]=='F')||(c[2]=='F'&&d[2]=='D')){
		cout<<"11";
		return 0;
	}
	else if((c[2]>='A'&&c[2]<='C')&&(d[2]>='A'&&d[2]<='C')){
		cout<<1;
		if(c[2]=='A'&&d[2]=='B'){
			cout<<1;
			return 0;
		}
		else if(c[2]=='B'&&d[2]=='C'){
			cout<<1;
			return 0;
		}
		else{
			cout<<0;
			return 0;
		}
	}
	else{
		cout<<"00";
	}
	return 0;
}
