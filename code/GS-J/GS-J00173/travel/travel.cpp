#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,e;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a1,b1;
	cin>>a>>a1>>b>>b1;
	if(int(a1[2])==65 || int(a1[2])==66 || int(a1[2])==67)c=1;
	else if(int(a1[2])==68 || int(a1[2])==69)c=2;
	if(int(b1[2])==65 || int(b1[2])==66 || int(b1[2])==67)d=1;
	else if(int(b1[2])==68 || int(b1[2])==69)d=2;
	if(a==b)cout<<1;
	else cout<<0;
	if(a1[0]==b1[0] && a1[1]==b1[1] && a==b){
		cout<<1;
	}else cout<<0;
	if(a1[0]==b1[0] && a1[1]==b1[1] && a==b && c==d)cout<<1;		
	else cout<<0;
	if(a1[0]==b1[0] && a1[1]==b1[1] && a==b && c==d && (a1[2]+1==b1[2] || b1[2]+1==a1[2])){
		cout<<1;
	}else cout<<0;
	return 0;
}
