#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
	string a1,a2,b1,b2;
	bool f1=0,f2=0,f3=0;
	cin>>a1>>b1>>a2>>b2;
	for(int i=0;i<2;i++){
        if(a1[i]!=a2[i]){
            f1=1;
            break;
        }
	}
	if(f1==1){
        cout<<"0";
	}else{
        cout<<"1";
	}
	for(int i=0;i<2;i++){
        if(b1[i]!=b2[i]){
            f2=1;
            break;
        }
	}
	if(f2==0&&f1==0){
        cout<<"1";
	}else{
        cout<<"0";
	}
    if(b1[2]=='F'&&b2[2]=='D'&&f2==0){
        cout<<"1";
    }else if(b1[2]=='D'&&b2[2]=='F'&&f2==0){
        cout<<"1";
    }else if(b1[2]=='A'&&b2[2]=='B'&&f2==0){
        cout<<"1";
    }else if(b1[2]=='B'&&b2[2]=='A'&&f2==0){
        cout<<"1";
    }else if(b1[2]=='B'&&b2[2]=='C'&&f2==0){
        cout<<"1";
    }else if(b1[2]=='C'&&b2[2]=='B'&&f2==0){
        cout<<"1";
    }else if(b1[2]=='A'&&b2[2]=='C'&&f2==0){
        cout<<"1";
    }else if(b1[2]=='C'&&b2[2]=='A'&&f2==0){
        cout<<"1";
    }else{
        cout<<"0";
        f3=1;
    }
    if(abs(b1[2]-b2[2])==1&&f3==0){
        if(b1[2]=='C'&&b2[2]=='D'){
            cout<<"0";
        }else{
            cout<<"1";
        }
    }else{
        cout<<"0";
    }
	return 0;
}
