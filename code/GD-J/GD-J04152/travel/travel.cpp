#include<bits/stdc++.h>
using namespace std;
char c,c2,c3;
int Zy1,Po1,He1,Zy2,Po2,He2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>c2;
	if(c=='1') Zy1=10;
	Zy1+=c2-'0';
	cin>>c>>c2>>c3;
	if(c=='1') Po1=10;
	Po1+=c2-'0';
	He1=c3-'A';
	cin>>c>>c2;
	if(c=='1') Zy2=10;
	Zy2+=c2-'0';
	cin>>c>>c2>>c3;
	if(c=='1') Po2=10;
	Po2+=c2-'0';
	He2=c3-'A';
	if(Zy1==Zy2) cout<<"1";
	else cout<<"0";
	if(Zy1==Zy2&&Po1==Po2) cout<<"1";
	else cout<<"0";
	if(Zy1==Zy2&&Po1==Po2&&(He1<3&&He2<3||He1>=3&&He2>=3)){
		cout<<"1";
		if(He1>He2) swap(He1,He2);
		if(He2==He1+1&&He1!=2) cout<<"1";
		else cout<<"0";
	}
	else cout<<"00";
	
}
