#include<bits/stdc++.h>
using namespace std;
string ca,cb,cc,cd;
int k;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.ans","w",stdout);
	cin>>ca>>cb>>cc>>cd;
	if(ca==cc){
		cout<<1;
	}
	else cout<<"0000",exit(0);
	if(cb[0]==cd[0]&&cb[1]==cd[1]){
		cout<<1;
		k=1;
	}
	else cout<<0;
	if(k==1&&((cb[2]<='C'&&cd[2]<='C')||(cb[2]>'C'&&cd[2]>'C'))){
		cout<<1;
		k=2;
	}
	else cout<<0;
	if(k==2){
		if(char(cb[2]+1)==cd[2]||char(cd[2]+1)==cb[2])cout<<1;
		else cout<<0;
	}
	else cout<<0;
	return 0;
}
