#include<bits/stdc++.h>
using namespace std;
string s1,s2,x1,x2;
char a='A',b='B',c='C',d='D',e='E';
bool asdf1(char q,char w){
	if(q==a){
		if(w==b){
			return 1;
		}else if(w==c){
			return 1;
		}
	}if(q==b){
		if(w==a){
			return 1;
		}else if(w==c){
			return 1;
		}
	}if(q==c){
		if(w==b){
			return 1;
		}else if(w==a){
			return 1;
		}
	}if(q==d){
		if(w==e){
			return 1;
		}
	}if(q==e){
		if(w==d){
			return 1;
		}
	}return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	//cout.tie(0);
	cin>>s1>>s2>>x1>>x2;
	if(s1==x1){
		cout<<"1";
	}else {
		cout<<"0000";
		return 0;
	}
		if((s2[0]=x2[0])&&(s2[1]=x2[1])){
		cout<<"1";
	}else {
		cout<<"000";
		return 0;
	}
			if(asdf1(s2[2],x2[2])){
				cout<<"1";
			}
			else {
				cout<<"00";
				return 0;
			}
			if((s2[2]-x2[2]==1)||(x2[2]-s2[2]==1)){
				cout<<"1";
			}else cout<<"0";
	//cout<<setpresition<<<<fixed<<"/n";
	return 0;
}
