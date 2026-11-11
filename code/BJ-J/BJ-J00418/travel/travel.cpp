#include<bits/stdc++.h>
using namespace std;
int a,b;
string aa,bb;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>aa>>b>>bb;
	if(a==b){
		cout<<1;
	}
	else cout<<0;
	int na=(aa[0]-'0')*10+(aa[1]-'0');
	int nb=(bb[0]-'0')*10+(bb[1]-'0');
	if(a==b&&na==nb){
		cout<<1;
	}
	else cout<<0;
	int ax=aa[2]-'A'+1;
	if(aa[2]=='F')ax=5;
	int bx=bb[2]-'A'+1;
	if(bb[2]=='F')bx=5;
	if(a==b&&na==nb&&((ax<=3&&bx<=3)||(ax>3&&bx>3))){
		cout<<1;
	}
	else cout<<0;
	if(a==b&&na==nb&&((ax<=3&&bx<=3)||(ax>3&&bx>3))&&(abs(ax-bx)==1)){
		cout<<1;
	}
	else cout<<0;
}
