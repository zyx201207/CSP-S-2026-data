#include<bits/stdc++.h> 
using namespace std;
string c1,s1,c2,s2;
int a1,a2;
char r,x;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	a1=s1[0]*10+s1[1]*10;
	a2=s2[0]*10+s2[1]*10;
	r=s1[2],x=s2[2];
	if(c1!=c2) {
		cout<<"0000";
		return 0;
	} 
	if(a1!=a2){
		cout<<"1000";
		return 0;
	}
	if(r>x) swap(r,x);
	if(r<'D'&&x>'C'){
		cout<<"1100";
		return 0;
	}
	if(x-r==1) cout<<"1111";
	else cout<<"1110";
	return 0;
}
