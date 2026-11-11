#include<bits/stdc++.h>
using namespace std;
string a,b,x,y;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>x>>b>>y;
	if(a==b){
		cout<<1;
	}else{
		cout<<"0000";
		exit(0);
	}
	if(x[0]==y[0]&&x[1]==y[1]){
		cout<<1;
	}else{
		cout<<"000";
		exit(0);
	}
	int n=x[2]-'D';
	int m=y[2]-'D';
	if((n<0&&m<0)||(n>=0&&m>=0)){
		cout<<1;
	}else{
		cout<<"00";
		exit(0);
	}
	if(abs(n-m)==1){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
