#include<bits/stdc++.h>

using std::cin;
using std::cout;
using std::endl;
using std::cerr;

using std::string;

string as,bs;
int a,b;

string ans="";

int main(){
	std::ios::sync_with_stdio(0);
	cin.tie(nullptr);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>as>>b>>bs;
	//两张车票对应的座位是否在同一节车厢；
	if(a==b){
		ans+='1';
	}
	else{
		ans+='0';
	}
	//两张车票对应的座位是否在同一节车厢的同一排；
	if(ans[0]=='1'&&as[0]==bs[0]&&as[1]==bs[1]){
		ans+='1';
	}
	else{
		ans+='0';
	}
	//两张车票对应的座位是否在同一节车厢的同一排，且位于过道的同一侧；
	if(ans[1]=='1'&&((as[2]<='C'&&bs[2]<='C')||(as[2]>'C'&&bs[2]>'C'))){
		ans+='1';
	}
	else{
		ans+='0';
	}
	//两张车票对应的座位是否相邻。
	if(ans[2]=='1'&&abs((int)as[2]-bs[2])==1){
		ans+='1';
	}
	else{
		ans+='0';
	}
	
	cout<<ans;
	return 0;
} 
/*
02 01A 02 01B
1111
02 01C 02 01A
1110
02 01C 02 01D
1100
02 02B 02 01A
1000
02 01A 03 01A
0000
*/
