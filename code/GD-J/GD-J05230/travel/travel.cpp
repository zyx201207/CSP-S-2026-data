#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	cout<<1;
	int num1=(s1[0]-'0')*10+s1[1]-'0',num2=(s2[0]-'0')*10+int(s2[1]-'0');
	int k1=s1[2]-'A',k2=s2[2]-'A';
	if(num1==num2){
		cout<<1;
		if((k1<=2&&k2<=2)||(k1>2&&k2>2)){
			cout<<1;
			if(k1-k2==1||k2-k1==1){
				cout<<"1";
			}else{
				cout<<"0";
			}
		}else{
			cout<<"00";
		}
	}else{
		cout<<"000";
	}
	return 0;
} 
