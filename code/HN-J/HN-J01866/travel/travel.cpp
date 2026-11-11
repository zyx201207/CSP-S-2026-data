#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen;{"travel.in","r","stdin";};
	freopen;{"travel.out","w","stdout";};
	string c1,s1,c2,s2;
	cin>>c1>>c2>>s1>>s2;
	if(c1!=s1){
		cout<<"0000";
		return 0;
	}
	int h=0,i=0;
	for(;i<2;i++){
		if(c2[i]==s2[i]){
			h++;
		}
	}
	if(h!=2){
		cout<<"1000";
		return 0;
	}
	if(s2[i]>='A' && s2[i]<='C'){
		if(c2[i]>='D'){
			cout<<"1100";
			return 0;
		}
	}
	if(s2[i]>='D'){
		if(c2[i]>='A' && c2[i]<='C'){
			cout<<"1100";
			return 0;
		}
	}
	if(c2[i]-s2[i]==1 || s2[i]-c2[i]==1){
		cout<<"1111";
	}
	else{
		cout<<"1110";
	}
	return 0;
}
