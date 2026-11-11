#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char d11,d12,d21,d22,d23,d31,d32,d41,d42,d43;
	cin>>d11>>d12>>d21>>d22>>d23>>d31>>d32>>d41>>d42>>d43;
	if(d11==d31&&d12==d32){
		cout<<"1";
		if(d21==d41&&d22==d42){
			cout<<"1";
			if((d23<='C'&&d43<='C')||(d23>='D'&&d43>='D')){
				cout<<"1";
				if(d23-d43==1||d23-d43==-1){
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
	fclose(stdin);
	fclose(stdout);
}
