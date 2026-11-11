#include<bits/stdc++.h>
using namespace std;

int ca,cb;
string stra,strb;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>ca>>stra>>cb>>strb;
	if(ca==cb){
		cout<<"1";
		if(stra[0]==strb[0]&&stra[1]==strb[1]){
			cout<<"1";
			if(stra[2]<='C'&&strb[2]<='C'||stra[2]>='D'&&strb[2]>='D'){
				cout<<"1";
				if(abs(int(stra[2]-strb[2]))==1)	cout<<"1";
				else	cout<<"0";
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
