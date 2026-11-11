#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d,e;
	cin>>a>>b>>c>>d;
	if(a[1]==c[1]){
		e+='1';
	}else{
		cout<<"0000";
			return 0;
	}
		if(b[1]==d[1]){
		e+='1';
	}else{
		cout<<"1000";
			return 0;
	}
		if(b[2]<='C'&&d[2]<='C'){
		e+='1';
	}else{
		if(b[2]>'C'&&d[2]>'C'){
			e+='1';
		}else{
			cout<<"1100";
		}
	}
		if(b[2]+1==d[2]||b[2]-1==d[2]){
		e+='1';
	}else{
		cout<<"1110";
			return 0;
	}
	cout<<e;
	fclose(stdin);
    fclose(stdout);
	return 0;
}
