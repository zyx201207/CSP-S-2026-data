#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c,c2,s,s2,a[4]={"0","0","0","0"};
	cin>>c>>s>>c2>>s2;
	if(c==c2){
		a[0]="1";
	}
	if(a[0]=="1"){
		if(s[0]==s2[0] && s[1]==s2[1]){
			a[1]="1";
		}
	}
	if(a[1]=="1"){
		if(s2[2]-'A'<=2 && s[2]-'A'<=2) {
				a[2]="1";
		}else if(s2[2]-'A'>2 && s[2]-'A'>2) {
				a[2]="1"; 
		}
	}
	if(a[2]=="1"){
		if(s[2]-s2[2]==-1 || s[2]-s2[2]==1){
				a[3]="1";
		}
	}
	cout<<a[0]<<a[1]<<a[2]<<a[3];
	return 0;
}
