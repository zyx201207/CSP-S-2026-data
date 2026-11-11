#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string ac,aw,bc,bw,da,db;
char ba,bb;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>ac>>aw>>bc>>bw;
	da=aw[0]+aw[1];
	db=bw[0]+bw[1];
	ba=aw[2];
	bb=bw[2];
	if(ac==bc){
		cout<<1;
	}else{
		cout<<0;
	}
	
	
	if(da==db && ac==bc){
		cout<<1;
	}else{
		cout<<0;
	}
	
	
	if(((ba<='C' && bb<='C') || (ba>='D' && bb>='D'))
	&& da==db && ac==bc){
		cout<<1;
	}else{
		cout<<0;
	}
	if(abs(ba-bb)==1 && da==db && ac==bc
	&& ((ba<='C' && bb<='C') || (ba>='D' && bb>='D'))){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
