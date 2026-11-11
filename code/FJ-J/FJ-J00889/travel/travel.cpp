#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string q,w,e,r;
	cin>>q>>w>>e>>r;
	if(q==e)cout<<"1";
	else return cout<<"0000",0;
	bool o=1;
	for(int i=0;i<2;++i){
		if(w[i]!=r[i]){
		return cout<<"000",0;}
	}
	if(o==1)cout<<"1";
	if((w[2]=='D'&&r[2]=='F')||(w[2]=='F'&&r[2]=='D')||(w[2]!='D'&&r[2]!='F'&&w[2]!='F'&&r[2]!='D')){
		cout<<"1";
	}else return cout<<"00",0;
	if(abs(r[2]-w[2])==1)cout<<"1";
	else cout<<"0";
	return 0;
} 
