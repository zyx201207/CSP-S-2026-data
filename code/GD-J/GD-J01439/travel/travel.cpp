#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//const int N;
string c1,s1;
string c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	} 
	cout<<'1';
	string p1=s1.substr(0,2);
	string p2=s2.substr(0,2);
	char z1=s1[2];
	char z2=s2[2];
	if(p1!=p2){
		cout<<"000";
		return 0;
	}
	cout<<'1';
	if(z1<='C'&&z2<='C'||z1>'C'&&z2>'C'){
		cout<<'1';
	}
	else{
		cout<<"00";
		return 0; 
	}
	if(abs(z2-z1)==1){
		cout<<'1';
	}
	else{
		cout<<'0';
		return 0;
	}
	
	return 0;
}
