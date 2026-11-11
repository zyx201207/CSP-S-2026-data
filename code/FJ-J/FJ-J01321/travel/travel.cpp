#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	int x=(b[0]-'0')*10+b[1]-'0',y=(d[0]-'0')*10+d[1]-'0';
	char s=b[2],l=d[2];
	if(a==c){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	
	
	if(x==y){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	
	if(s>l){
		swap(s,l);
	}
	if(s==l||(s=='D'&&l=='F')||(s=='A'&&l=='B')||(s=='A'&&l=='C')||(s=='B'&&l=='C')){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}
	
	
	if(abs(x-y)<=1&&abs(s-l)<=1){
		cout<<1;
	}else{
		cout<<0;
	}
	
	
	return  0;
}
