#include<bits/stdc++.h>
using namespace std;
const int N=0;
long long n;
string a,b,ac,bc;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>ac>>a>>bc>>b;
    if(ac==bc){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	string ta="",tb="";
	ta+=a[0];
	ta+=a[1];
	tb+=b[0];
	tb+=b[1];
	if(ta==tb){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	if((a[2]<'D'&&b[2]<'D')||(a[2]>'C'&&b[2]<'D')){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}
	if(a[2]+1==b[2]||a[2]-1==b[2]){
		cout<<1;
	}else{
		cout<<0;
	}
    return 0;
}
