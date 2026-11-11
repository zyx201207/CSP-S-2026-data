#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000"<<endl;
		return 0;
	}
	cout<<"1";
	int x=(s1[0]-'0')*10+(s1[1]-'0'),y=(s2[0]-'0')*10+(s2[1]-'0');
	if(x!=y){
		cout<<"000"<<endl;
		return 0;
	}
	cout<<"1";
	char ch1=s1[s1.size()-1],ch2=s2[s2.size()-1];
	if((ch1>='A'&&ch1<='C'&&ch2>='A'&&ch2<='C')||(ch1>='D'&&ch1<='F'&&ch1>='D'&&ch1<='F')){
		cout<<"1";
	}
	else{
		cout<<"00"<<endl;
		return 0;
	}
	if((ch1>ch2&&ch1-ch2==1)||(ch1<ch2&&ch2-ch1==1)){
		cout<<"1";
	}
	else cout<<"0";
	return 0;
}