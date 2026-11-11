/*
03 03D 03 03A
1100
03 17D 03 15D
1000
02 15F 01 15D
0000
02 15F 02 15D
1111
17 18F 17 18A
1100
17 18C 17 18A
1110
*/
#include<bits/stdc++.h> 
using namespace std;
string a,b,c,d;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	int s1=(b[0]-'0')*10+(b[1]-'0');
	int s2=(d[0]-'0')*10+(d[1]-'0');
	if(s1==s2){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	char c1=b[2],c2=d[2];
	if((c1>='A'&&c1<='C'&&c2>='D'&&c2<='F')||(c2>='A'&&c2<='C'&&c1>='D'&&c1<='F')){
		cout<<"00";
		return 0;
	}else{
		cout<<1;
	}
	if(c1=='C'&&c2=='A'||c2=='C'&&c1=='A') cout<<0;
	else cout<<1;
	return 0;
}
