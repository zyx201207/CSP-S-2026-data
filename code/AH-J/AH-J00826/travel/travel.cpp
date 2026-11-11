#include<bits/stdc++.h>
using namespace std;
string s1,s2,c1,c2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s1>>s2>>c1>>c2;
	bool f=true;
	for(int i=0;i<2;i++){
		if(s1[i]!=c1[i]){
			f=false;
			break;
		}
	}
	if(!f){
		cout<<"0000";
		return 0;
	}
	cout<<1;
	for(int i=0;i<2;i++){
		if(s2[i]!=c2[i]){
			f=false;
			break;
		}
	}
	if(!f){
		cout<<"000";
		return 0;
	}
	cout<<1;
	if((s2[2]>='D'&&c2[2]>='D')||(s2[2]<='C'&&c2[2]<='C')){
		cout<<1;
	}else {
		cout<<"00";
		return 0;
	}
	if(s2[2]>='D'&&c2[2]>='D'){
		cout<<1;
	}else if(s2[2]<='C'&&c2[2]<='C'){
		int a=int(s2[2]),b=int(c2[2]);
		if(abs(a-b)==1){
			cout<<1;
			return 0;
		}
		cout<<0;
	}
	return 0;
}
