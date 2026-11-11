#include<iostream>
#include<cstdio>
using namespace std;
string a1,a2,b1,b2,c1,c2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a2>>b1>>b2;
	if(a1==b1) cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	for(int i=0;i<=1;i++){
		if(a2[i]!=b2[i]){ 
			cout<<"000";
			return 0;
		}
	}
	cout<<1;
	if(a2[2]=='A'||a2[2]=='B'||a2[2]=='C'){
		if(b2[2]=='A'||b2[2]=='B'||b2[2]=='C'){
			if(a2[2]=='B'||b2[2]=='B'){
				cout<<"11";
				return 0;
			}
			cout<<"10";
			return 0;
		}else{
			cout<<"00";
			return 0;
		}
	}
	if(a2[2]=='D'||a2[2]=='F'){
		if(b2[2]=='D'||b2[2]=='F'){
			cout<<"11";
			return 0;
		}else{
			cout<<"00";
			return 0;
		}
	}
}
