#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int a,b,c,d;
	char n,m;
	cin>>a>>b>>n>>c>>d>>m;
	if(a!=c){
		cout<<"0000";
	}else if(b!=d){
		cout<<"1000";
	}else if(!(n<='C'&&m<='C'||n>='C'&&m>'C')){
		cout<<"1100";
	}else if(!(n-1==m||n+1==m)){
		cout<<"1110";
	}else{
		cout<<"1111";
	}
	return 0;
}
