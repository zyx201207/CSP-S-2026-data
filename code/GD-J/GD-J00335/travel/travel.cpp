#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}
	else{
		for(int i=1;i<=4;i++){
			cout<<0;
		}
		return 0;
	}
	string seat1,seat2;
	for(int i=0;i<=1;i++){
		seat1+=s1[i];
		seat2+=s2[i];
	}
	if(seat1==seat2){
		cout<<1;
	}
	else{
		for(int i=1;i<=3;i++){
			cout<<0;
		}
		return 0;
	}
	char sit1=s1[2],sit2=s2[2];
	if((sit1>='D'&&sit1<='F'&&sit2>='D'&&sit2<='F')||(sit1>='A'&&sit1<='C'&&sit2>='A'&&sit2<='C')){
		cout<<1;
	}
	else{
		for(int i=1;i<=2;i++){
			cout<<0;
		}
		return 0;
	}
	int flag=abs(sit1-sit2);
	if(flag==1){
		cout<<1;
	}
	else cout<<0;
	return 0;
}
