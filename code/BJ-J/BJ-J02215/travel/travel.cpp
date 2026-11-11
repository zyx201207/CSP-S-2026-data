#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","r",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	int f=1,f1=1,b1,d1;
	b1=b[2]-'A'+1;
	d1=d[2]-'A'+1;
	for(int i=0;i<2;i++){
		if(a[i]!=c[i]) f=0;
	}
	for(int i=0;i<2;i++){
		if(b[i]!=d[i]) f1=0;
	}
	if(f==1){
		cout<<"1";
		if(f1==1){
			cout<<"1";
			if(b1<=3&&d1<=3||b1>3&&d1>3){
				cout<<"1";
				if(b1-d1==1||b1-d1==-1||b[2]=='D'&&d[2]=='F'||b[2]=='F'&&d[2]=='D'){
					cout<<"1";
				}else{
					cout<<"0";
				}
			}else{
                cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}