#include<bits/stdc++.h>
using namespace std;
void check(char a,char b){
	if('A'<=a && a<='C' && 'A'<=b && b<='C'){
		cout<<1;
		if(abs(a-b)<=1) cout<<1;
		else cout<<0;
	}
	else {
		if('D'<=a && a<='F' && 'D'<=b && b<='f'){
			cout<<11;
		}
		else {
			cout<<"00";
		}
	}
	return;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<1;
			check(s1[2],s2[2]);
		}
		else {
			cout<<"000";
		}
	}
	else {
		cout<<"0000";
	}
	return 0;
}
