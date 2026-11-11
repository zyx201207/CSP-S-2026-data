#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int cnt(string s){
	int ans=(s[0]-'0')*10+(s[1]-'0');
	return ans;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int a1=cnt(c1),a2=cnt(c2);
	int b1=cnt(s1),b2=cnt(s2);
	int d1=(s1[2]-'A'),d2=(s2[2]-'A');
	if(a1!=a2){
		cout<<"0000";
		return 0;
	}
	cout<<"1";
	if(b1!=b2){
		cout<<"000";
		return 0;
	}
	cout<<"1";
	if((d1<=2&&d2>=3)||(d1>=3&&d2<=2)){
		cout<<"00";
		return 0;
	}
	cout<<"1";
	if(abs(d1-d2)==1)cout<<"1";
	else cout<<"0";
	return 0;
} 
