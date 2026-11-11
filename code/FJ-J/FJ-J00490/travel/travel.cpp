#include<bits/stdc++.h>
using namespace std;
int af,bf,ap,bp;
string a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>af>>a>>bf>>b;
	ap=a[2]-'A'+1;
	bp=b[2]-'A'+1;
	if(af==bf){cout<<1;
		if(a[1]==b[1]&&a[0]==b[0]){
		if(ap<=3&&bp<=3){
			if(ap-bp==1||ap-bp==-1)	cout<<111;
			else cout<<110;
		}
		else if(ap>3&&bp>3){
			cout<<111;
		}
		else	cout<<100;
	}
	else	cout<<"000";
	}
	else cout<<"0000";
	
	return 0;
}
