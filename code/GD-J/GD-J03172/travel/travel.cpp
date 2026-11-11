#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a!=c){
		cout<<"0000";
		return 0;
	}
	int x=(b[0]-'0')*10+b[1]-'0',y=(d[0]-'0')*10+d[1]-'0';
	if(x!=y){
		cout<<"1000";
		return 0;
	}
	if(!((b[2]=='A'&&(d[2]=='B'||d[2]=='C'))||(b[2]=='B'&&(d[2]=='A'||d[2]=='C'))||(b[2]=='C'&&(d[2]=='B'||d[2]=='A'))||(b[2]=='D'&&d[2]=='F')||(b[2]=='F'&&d[2]=='D'))){
		cout<<"1100";
		return 0;
	}
	if(b[2]-1!=d[2]&&b[2]+1!=d[2]){
		cout<<"1110";
		return 0;
	}
	cout<<"1111";
	return 0;
}
