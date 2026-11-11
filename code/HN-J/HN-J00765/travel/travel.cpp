#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a[0]==c[0]&&a[1]==c[1]){
		cout<<1;
	}else{
		cout<<0<<0<<0<<0;
		return 0;
	}//是否在一列车相 
	if(b[0]==d[0]&&b[1]==d[1]){
		cout<<1;
	}else{
		cout<<0<<0<<0;
		return 0;
	}//是否在同一排 
	if(b[2]<='C'&&d[2]<='C'){
		cout<<1;
	}else if(b[2]>'C'&&d[2]>'C'){
		cout<<1;
	}else{
		cout<<0<<0;
		return 0;
	}//是否在同一排
	if(b[2]-d[2]==1||d[2]-b[2]==1){
		cout<<1;
	}
	else{
		cout<<0;
	} 
	return 0;

} 
