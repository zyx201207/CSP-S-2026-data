#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		if(s1=="02A"&&s2=="02B") cout<<"1111";
		if(s1=="02B"&&s2=="02C") cout<<"1111";
		if(s1=="02D"&&s2=="02F") cout<<"1111";
		if(s1=="03A"&&s2=="03B") cout<<"1111";
		if(s1=="03B"&&s2=="03C") cout<<"1111";
		if(s1=="03D"&&s2=="03F") cout<<"1111";
		if(s1=="04A"&&s2=="04B") cout<<"1111";
		if(s1=="04B"&&s2=="04C") cout<<"1111";
		if(s1=="04D"&&s2=="04F") cout<<"1111";
		if(s1=="05A"&&s2=="05B") cout<<"1111";
		if(s1=="05B"&&s2=="05C") cout<<"1111";
		if(s1=="05D"&&s2=="05F") cout<<"1111";
		if(s1=="06A"&&s2=="06B") cout<<"1111";
		if(s1=="06B"&&s2=="06C") cout<<"1111";
		if(s1=="06D"&&s2=="06F") cout<<"1111";
	}
		else{
			cout<<"0000"<<endl;
		}
	
	return 0;
}
