#include<bits/stdc++.h>
using namespace std;
int a,as,b,bs;
char ch1,ch2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin>>a>>as>>ch1>>b>>bs>>ch2;
	if(a!=b){
		cout<<"0000";
		return 0;
	}
	cout<<1;
	if(as!=bs){
		cout<<"000";
		return 0;
	}
	cout<<1;
	if(ch1>='D'&&ch2>='D'){
		cout<<"11";
	}
	else if(ch1<='C'&&ch2<='C'){
		if(abs(ch1-ch2)==1) cout<<11;
		else cout<<10;
	}
	else cout<<"00";
	return 0;
}
/*16 03C 15 03D
02 03F 02 04D
02 03D 02 03C
02 03D 02 03F
02 03B 02 03A
02 03A 02 03B
02 03C 02 03A*/
