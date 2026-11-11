#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2,c3,c4;
	cin>>c1>>c2>>c3>>c4;
	bool cmp1=1,cmp2=1;
	if(c1!=c3){
		cout<<"0000";
		return 0;
	}else{
		cout<<1;
	}
	if(c2[0]==c4[0]&&c2[1]==c4[1]){
		cout<<1;
		if((c2[2]<='C'&&c4[2]<='C')||(c2[2]>'C'&&c4[2]>'C')){
			cout<<1;
		}else{
			cout<<0;
			cmp1=0;
		}
	}else{
		cout<<"00";
		cmp1=0;
	}
	if(cmp1&&abs(c2[2]-c4[2])==1){
		cout<<1;
	}else{
		cout<<0;
	}
    return 0;
}
