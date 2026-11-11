#include<bits/stdc++.h>
#define itn int
using namespace std;

signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a1,a2;
	string b1,b2;
	cin>>a1>>b1>>a2>>b2;
	if(a1!=a2){
		cout<<"0000";
		return 0; 
	}
	int cnt1=0,cnt2=0;
	string seat1,seat2;
	for(int i=0;i<=b1.size();i++){
		if(b1[i]<='9'&&b1[i]>='0'){
			cnt1*=10;
			cnt1=cnt1+int(b1[i])-'0';
		}else{
			seat1+=b1[i];
		}
	}
	for(int i=0;i<=b2.size();i++){
		if(b2[i]<='9'&&b2[i]>='0'){
			cnt2*=10;
			cnt2=cnt2+int(b2[i])-'0';
		}else{
			seat2+=b2[i];
		}
	}
	if(cnt1!=cnt2){
		cout<<"1000";
		return 0;
	}
	if(seat1[0]=='C'&&seat2[0]=='D'){
		cout<<"1100";
		return 0;
	}
	if(seat2[0]=='C'&&seat1[0]=='D'){
		cout<<"1100";
		return 0;
	}
	if(abs(int(seat1[0])-int(seat2[0]))==1){
		cout<<"1111";
		return 0;
	}
	cout<<"1110";
	return 0;
}
