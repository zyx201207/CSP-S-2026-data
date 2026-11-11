#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
char r1,xx;
int r,x;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	cout<<'1';
	for(int i=0;i<2;i++){
		r=r*10+s1[i]-'0';
		x=x*10+s2[i]-'0';
	}
	r1=s1[2];
	xx=s2[2];
	if(x==r) cout<<'1';//2
	else{
		cout<<"000";
		return 0;
	}
	if((r1>='A' && r1<='C' && xx>='A' && xx<='C') || (r1>='D' && r1<='E' && xx>='D' && xx<='E')) cout<<'1';//3
	else{
		cout<<"00";
		return 0;
	}
	if((r1>='A' && r1<='C' && xx>='A' && xx<='C') || (r1>='D' && r1<='E' && xx>='D' && xx<='E')){
		if((r1+1==xx && xx-1==r1)){
			cout<<'1';
		}
		else{
		cout<<'0';
		return 0;
		}
	}//4
	else cout<<'0';
	return 0;
}
//(r>3 && r<=5 && x>3 && x<=5 ) || (r<=3 && x<=3)
