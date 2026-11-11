#include <bits/stdc++.h>
using namespace std;
char c1[20],s1[20],c2[20],s2[20];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]!=c2[0] ||c1[1]!=c2[1]||c1[3]!=c2[3]){
		cout<<"0000";
		return 0;
	}
	if(s1[0]!=s2[0] ||s1[1]!=s2[1]){
		cout<<"1000";
		return 0;
	}
	int h=s1[2],h2=s2[2];
	h-='A';
	h2-='A';
	if((h>2&&h2<=2)||(h<=2&&h2>2)){
		cout<<"1100";
		return 0;
	}
	if(h-h2==1 ||h2-h==1){
		cout<<"1111";
	}
	else{
		cout<<"1110";
	}
	
	return 0;
}
