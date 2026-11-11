#include<bits/stdc++.h>
using namespace std;
int a,c;
char b,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	if(b>d){
		if(b-d>5){
			cout<<"000";
			return 0;
		}else{
			cout<<"1";
		}
	}else{
		if(d-b>5){
			cout<<"000";
			return 0;
		}else{
			cout<<"1";
		}
	}
	if(b-d<5){
		cout<<"1";
	}else{
		cout<<"00";
		return 0;
	}
	if(b-d==1 || b-d==-1){
		cout<<"1";
	}else{
		cout<<"0";
	}
	return 0;
}
