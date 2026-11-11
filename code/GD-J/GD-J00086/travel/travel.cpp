#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	int n;
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	if(b[0]==d[0]&&b[1]==d[1]){
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
	if((int(b[2])<=int('C')&&int(d[2])<=int('C'))||(int(b[2])>int('C')&&int(d[2])>int('C'))){
		cout<<"1";
	}else{
		cout<<"00";
		return 0;
	}
	int x=int(b[2]),y=int(d[2]);
	if(x<y){
		swap(x,y);
	}
	if(x-y==1&&(x!=int('D')&&y!=int('C'))){
		cout<<"1";
	}else{
		cout<<"0";
		return 0;
	}
	return 0;
} 
