#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int ac,ap,bc,bp;
	char az,bz;
	cin>>ac>>ap>>az>>bc>>bp>>bz;
	if(ac==bc){
		cout<<1;
		if(ap==bp){
			cout<<1;
			if((az<='C'&&bz<='C')||(az>'C'&&bz>'C')){
				cout<<1;
				if(abs(az-bz)==1) cout<<1;
				else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	
	return 0;
}

