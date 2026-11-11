#include<bits/stdc++.h>
using namespace std;
string c,s,cc,ss;
bool chek1(char a){
	if(a>='A'&&a<='C')return 1;
	else return 0;
}
bool chek2(char b){
	if(b>='D'&&b<='F')return 1;
	else return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>c>>cc>>s>>ss;
	if(c==s){//same chexiang
		cout<<1;
	}else{
		cout<<0;
		cout<<0<<0<<0;
		return 0;
	}
	if(cc[0]==ss[0]&&cc[1]==ss[1]){//samechexiang and same pai
		cout<<1;
		if((chek1(cc[2])&&chek1(ss[2]))||(chek2(ss[2])&&chek2(cc[2]))){//same zuoyou
			cout<<1;
			if(abs(cc[2]-ss[2])==1){
				cout<<1;
			}else{
				cout<<0;
			}
		}else{
			cout<<0<<0;
		}
	}else{
		cout<<0;
		cout<<0;
		cout<<0;
	}
	return 0;

}