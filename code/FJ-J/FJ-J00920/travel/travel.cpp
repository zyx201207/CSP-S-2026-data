#include<bits/stdc++.h>
#define file(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout);
#define int long long
#define IOimprove ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
int ge(char x){
	if(x=='F')return 5;
	else return x-'A'+1;
}
signed main(){
	file("travel")
	IOimprove;
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a!=c){
		cout<<"0000";
		return 0;
	}
	else{
		string e=b.substr(0,2),f=d.substr(0,2);
		if(e!=f){
			cout<<"1000";
			return 0;
		}
		char g=b[2],h=d[2];
		int i=ge(g),j=ge(h);
		if((i<=3&&j<=3)||(i>3&&j>3)){
			if(abs(i-j)==1){
				cout<<"1111";
				return 0;
			}
			else{
				cout<<"1110";
				return 0;
			}
		}
		else{
			cout<<"1100";
			return 0;
		}
	}
	return 0;
}
