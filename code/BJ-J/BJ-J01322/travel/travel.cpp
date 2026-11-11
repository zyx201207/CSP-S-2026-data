#include<bits/stdc++.h>
using namespace std;
int aa,ab,ac,ba,bb,bc;
void into(){
	cin>>aa;
	char c;
	cin>>c;
	ab=ab*10+c-'0';
	cin>>c;
	ab=ab*10+c-'0';
	cin>>c;
	ac=c-'A'+1;
	cin>>ba;
	cin>>c;
	bb=bb*10+c-'0';
	cin>>c;
	bb=bb*10+c-'0';
	cin>>c;
	bc=c-'A'+1;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	into();
	if(aa!=ba){
		cout<<"0000";
		return 0;
	}
	cout<<1;
	if(ab!=bb){
		cout<<"000";
		return 0;
	}
	cout<<1;
	if(((ac>=1&&ac<=3)&&(bc>=1&&bc<=3))||((ac>=4&&ac<=5)&&(bc>=4&&bc<=5))){
		cout<<1;
		if(abs(ac-bc)==1) cout<<1;
		else cout<<0;
	}
	else{
		cout<<"00";
	}
	return 0;
}
