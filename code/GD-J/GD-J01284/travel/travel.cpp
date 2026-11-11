#include<bits/stdc++.h>
using namespace std;
string a1,a2,b1,b2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a2>>b1>>b2;
	for(int i=0;i<a1.size();i++){
		if(a1[i]!=b1[i]){
			cout<<"0000";
			return 0;
		}
	}
	cout<<1;
	if(a2[0]!=b2[0]||a2[1]!=b2[1]){
		cout<<"000";
		return 0;
	}
	cout<<1;
	 if(a2[2]<='C'&&b2[2]>='D'||a2[2]>='D'&&b2[2]<='C'){
		cout<<"00";
		return 0;
	} 
	cout<<1;
	 if(abs(a2[2]-b2[2])!=1){
		cout<<0;
		return 0;
	} 
	cout<<1;
	return 0;
}
