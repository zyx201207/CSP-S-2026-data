#include<bits/stdc++.h>
using namespace std;
string sta,stb,stwa,stwb;

int main(){
	freopen("travel.in ","r",stdin);
	cin>>sta>>stwa>>stb>>stwb;
	if(sta==stb){
		cout<<1;
	}
	else{
		cout<<"0000";
		return 0;
	}
	if((stwa[0]==stwb[0])&&(stwa[1]==stwb[1])){
		cout<<1;
	}
	else{
		cout<<"000";
		return 0;
	}
	if(((stwa[2]-'C'<=0)&&(stwb[2]-'C'<=0))||((stwa[2]-'C'>0)&&(stwb[2]-'C'>0))){
		cout<<1;
		if(stwa[2]-'A'>0&&stwb[2]-'A'>0){
			cout<<1;
			return 0;
		}
	}
	else{
		cout<<"00";
		return 0;
	}
	if(abs(stwa[2]-stwb[2])==1){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
	freopen("travel.out ","w",stdout);
}