#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int cnt;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<1;
		cnt++;
	}
	else{
		cout<<0;
	}
	if(cnt==1 && b[0]==d[0] && b[1]==d[1]){
		cout<<1;
		cnt++;
	}
	else{
		cout<<0;
	}
	if(cnt==2 && b[2]<='C' && d[2]<='C'){
		cout<<1;
		cnt++;
	}
	else if(cnt==2 && b[2]>='D' && d[2]>='D'){
		cout<<1;
		cnt++;
	}
	else{
		cout<<0;
	}
	if(cnt==3 && (b[2]==d[2]+1 || b[2]==d[2]-1)){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}
