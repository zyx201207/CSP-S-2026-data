#include<bits/stdc++.h>
#define ci const int
#define ll long long int
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	string c1,s1,c2,s2,num1,num2;
	char sit1,sit2;
	cin >> c1 >> s1 >> c2 >> s2;
	num1=s1[0];
	num1+=s1[1];
	sit1=s1[2];
	num2=s2[0];
	num2+=s2[1];
	sit2=s2[2];
	if(c1==c2){
		cout << 1;
	}else{
		cout << "0000";
		return 0;
	}
	if(num1==num2){
		cout << 1;
	}else{
		cout << "000";
		return 0;
	}
	if((sit1=='A' && sit2=='B') || (sit1=='A' && sit2=='C') || (sit1=='B' && sit2=='C') || (sit1=='B' && sit2=='A') || (sit1=='C' && sit2=='A') || (sit1=='C' && sit2=='B') || (sit1=='D' && sit2=='F') || (sit1=='F' && sit2=='D')){
		cout << 1;
	}else{
		cout << "00";
		return 0;
	}
	if(abs(sit1-sit2)==1){
		cout << 1;
	}else{
		cout << 0;
	}
	return 0;
} 
