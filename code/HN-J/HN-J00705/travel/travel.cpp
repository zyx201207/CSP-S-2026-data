#include<bits/stdc++.h>
using namespace std;
int num(string s){
	int sum=0;
	for(int m=0;m<s.length();m++){
		sum+=(s[0]-'0')*pow(10,1-m);
	}
	return sum;
}
bool lr(char x){
	return (x=='A'||x=='B'||x=='C');
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int tr1=num(c1),tr2=num(c2);
	if(tr1==tr2) cout<<"1";
	else{
		cout<<"0000";
		return 0;
	}
	string zw1,zw2;
	zw1=s1[0]+s1[1];
	zw2=s2[0]+s2[1];
	if(num(zw1)==num(zw2)) cout<<"1";
	else{
		cout<<"000";
		return 0;
	} 
	if(lr(s1[2])==lr(s2[2])) cout<<"1";
	else{
		cout<<"00";
		return 0;
	}
	if(abs(s1[2]-s2[2])==1) cout<<"1";
	else cout<<"0";
	return 0;
}
