#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool check3(char x,char y){
	if((x=='A'||x=='B'||x=='C')&&(y=='D'||y=='F')) return 0;
	if((x=='D'||x=='F')&&(y=='A'||y=='B'||y=='C')) return 0;
	return 1;
}
bool check4(string x,string y){
	if(abs(x[2]-y[2])==1) return 1;
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<"1";
	else{
		cout<<"0000";
		return 0;
	}
	bool f=1;
	for(int i=0;i<s1.size()-1;i++){
		if(s1[i]!=s2[i]){
			cout<<"0";
			f=0;
			break;
		}
	}
	if(f) cout<<"1";
	int f2=0;
	if(f&&check3(s1[2],s2[2])){
		f2=1;
		cout<<"1";
	}
	else cout<<"0";
	if(f2&&check4(s1,s2)) cout<<"1";
	else cout<<"0";
	return 0;
}
