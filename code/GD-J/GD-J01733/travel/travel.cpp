#include<bits/stdc++.h>
using namespace std;
string a1,a2,b1,b2;
bool f1=0,f2=0,f3=0,f4=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a2>>b1>>b2;
	if(a1==b1) f1=1;
	if(f1&&a2[0]==b2[0]&&a2[1]==b2[1]) f2=1;
	if(f1&&f2){
		if(a2[2]<='C'&&b2[2]<='C') f3=1;
		if(a2[2]>='D'&&b2[2]>='D') f3=1;
	}
	if(f1&&f2&&f3){
		if(abs(int(a2[2]-b2[2]))==1) f4=1;
		if(a2[2]=='D'&&b2[2]=='F') f4=1;
		if(a2[2]=='F'&&b2[2]=='D') f4=1;
	}
	if(f1) cout<<"1";
	else cout<<"0";
	if(f2) cout<<"1";
	else cout<<"0";
	if(f3) cout<<"1";
	else cout<<"0";
	if(f4) cout<<"1";
	else cout<<"0";
	cout<<endl;
	return 0;
}
