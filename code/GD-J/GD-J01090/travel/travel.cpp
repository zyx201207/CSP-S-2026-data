#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a!=c){
		cout<<"0000";
		return 0;
	}
	int n=(b[0]-'0')*10+b[1]-'0';
	int m=(d[0]-'0')*10+d[1]-'0';
	if(n!=m){
		cout<<"1000";
		return 0;
	}
	if('A'<=b[2]&&b[2]<='C'&&'A'<=d[2]&&d[2]<='C'){
		if(b[2]+1==d[2]||d[2]+1==b[2]){
			cout<<"1111";
			return 0;
		}else{
			cout<<"1110";
			return 0; 
		}
	}else if('D'<=b[2]&&b[2]<='F'&&'D'<=d[2]&&d[2]<='F'){
		cout<<"1111";
		return 0;
	}else{
		cout<<"1100";
		return 0;
	}
}
