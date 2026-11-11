#include<bits/stdc++.h>
using namespace std;
int cr,cx,sr,sx;
char src,sxc;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>cr>>sr;
	cin>>src;
	cin>>cx>>sx;
	cin>>sxc;
	if(cr==cx){
		cout<<'1';
	}else{
		cout<<'0';
	}
	if(cr==cx&&sr==sx){
		cout<<'1';
	}else{
		cout<<'0';
	}
	if(cr==cx&&sr==sx&&((src<='C'&&sxc<='C')||(src>'C'&&sxc>'C'))){
		cout<<'1';
	}else{
		cout<<'0';
	}
	if(cr==cx&&sr==sx&&((src<='C'&&sxc<='C')||(src>'C'&&sxc>'C'))&&abs(int(src)-int(sxc))==1){
		cout<<'1';
	}else{
		cout<<'0';
	}
	return 0;
}
