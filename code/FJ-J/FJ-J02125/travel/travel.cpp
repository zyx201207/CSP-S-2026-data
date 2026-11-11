#include<bits/stdc++.h>
using namespace std;
string c1,c2,c3,c4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c1>>c2>>c3>>c4;
	if(c1==c3) cout<<1;
	else cout<<0;
	if(c1==c3&&c2[0]==c4[0]&&c2[1]==c4[1]){
		cout<<1;
	}
	else cout<<0;
	if(c1==c3&&c2[0]==c4[0]&&c2[1]==c4[1]&&c2[2]<='C'&&c4[2]<='C'||c2[2]>='D'&&c4[2]>='D'){
		cout<<1;
	}
	else{
		cout<<0;
	}
	int a=c2[2]-'0',b=c4[2]-'0';
	if(abs(a-b)==1&&c1==c3&&c2[0]==c4[0]&&c2[1]==c4[1]){
		if(c2[2]=='C'&&c4[2]=='D'||c2[2]=='D'&&c4[2]=='C') cout<<0;
		else cout<<1;
	}
	else cout<<0;
	return 0;
} 
