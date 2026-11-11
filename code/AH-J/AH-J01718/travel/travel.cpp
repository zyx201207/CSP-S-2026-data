#include<bits/stdc++.h>

#define DBG 0

using namespace std;

struct seat{

	int tn;

	string sn;

}a,b;

int rna,rnb,lna,lnb;

int main(){

	freopen("travel.in","r",stdin);

	freopen("travel.out","w",stdout);

	cin>>a.tn>>a.sn>>b.tn>>b.sn;

	rna=(a.sn[0]-'0')*10+(a.sn[1]-'0'),

	rnb=(b.sn[0]-'0')*10+(b.sn[1]-'0'),

	lna=a.sn[2]-'A'+1;

	lnb=b.sn[2]-'A'+1;

	if(lna==('F'-'A')) lna=('E'-'A');

	if(lnb==('F'-'A')) lnb=('E'-'A');

	if(a.tn==b.tn){

		cout<<(DBG?"CASE 1: 1\n":"1");

		if(rna==rnb){

			cout<<(DBG?"CASE 2: 1\n":"1");

			if(((lna<=3)&&(lnb<=3))||((lna>=4)&&(lnb>=4))){

				cout<<(DBG?"CASE 3: 1\n":"1");

				if(abs(lna-lnb)==1){

					cout<<(DBG?"CASE 4: 1\n":"1");

				} else cout<<(DBG?"CASE 4: 0\n":"0");

			} else cout<<(DBG?"CASE 3: 00\n":"00");

		} else cout<<(DBG?"CASE 2: 000\n":"000");

	} else cout<<(DBG?"CASE 1: 0000\n":"0000");

	if(DBG) cout<<endl<<rna<<" "<<lna<<"   "<<rnb<<" "<<lnb<<endl;

	return 0;

} 


