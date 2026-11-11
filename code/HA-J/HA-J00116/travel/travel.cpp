#include<bits/stdc++.h>
using namespace std;
string s,ss;
char c[10],cc[10];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>s>>c+1>>ss>>cc+1;
	if(s!=ss){
		cout<<"0000";
	}else if(c[1]!=cc[1]||c[2]!=cc[2]){
		cout<<"1000";
	}else if((c[3]<='C'&&cc[3]>'C')||(c[3]>'C'&&cc[3]<='C')){
		cout<<"1100";
	}else if(c[3]!=cc[3]+1&&c[3]!=cc[3]-1){
		cout<<"1110";
	}else{
		cout<<"1111";
	}
	return 0;
}

