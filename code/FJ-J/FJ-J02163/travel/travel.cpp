#include<bits/stdc++.h>
using namespace std;
string s1,s2;
int c1,c2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000"<<endl;
		return 0;
	}
	int x=(s1[0]-'0')*10+s1[1]-'0';
	int y=(s2[0]-'0')*10+s2[1]-'0';
	if(x==y){
		if((s1[2]<='C' && s2[2]<='C') ||(s1[2]>'C' && s2[2]>'C')){
			if(abs(s2[2]-s1[2])==1){
				cout<<"1111"<<endl;
			}else{
				cout<<"1110"<<endl;
			}
		}else{
			cout<<"1100"<<endl;
		}
	}else cout<<"1000"<<endl;
	
	return 0;
}
