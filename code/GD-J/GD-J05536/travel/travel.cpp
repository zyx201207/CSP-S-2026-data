#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int ac,ap,bc,bp;
	char az,bz;
	cin>>ac>>ap>>az;
	cin>>bc>>bp>>bz;
	//cout<<ac<<' '<<ap<<' '<<az<<endl;
	//cout<<bc<<' '<<bp<<' '<<bz<<endl;
	if(ac==bc){
		cout<<1;
		if(ap==bp){
			cout<<1;
			if(((az-'A'+1)<=3)==((bz-'A'+1)<=3)){
				cout<<1;
				if(abs(az-bz)==1){
					cout<<1;
				}
				else{
					cout<<0;
				}
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
}
