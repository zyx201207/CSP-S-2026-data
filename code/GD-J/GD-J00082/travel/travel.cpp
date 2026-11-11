#include<bits/stdc++.h>
using namespace std;
string ra,rb,ida,idb,cmpa,cmpb;
int posa,posb;
int main(){
//	freopen("travel.in","r",stdin);
//	freopen("travel.out","w",stdout);
	cin>>ra>>ida>>rb>>idb;
	if(ra==rb){
		cout<<1;
		cmpa=ida.substr(0,2);
		cmpb=idb.substr(0,2);
		posa=int(ida[2])-64;
		posb=int(idb[2])-64;		
		if(cmpa==cmpb){
			cout<<1;
			if((posa<=3&&posb<=3)||(posa>=4&&posb>=4)){
				cout<<1;
				if(abs(posa-posb)==1&&posa+posb!=7) cout<<1;
				else cout<<0;
			}else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
	cout<<endl;
	return 0;
} 
