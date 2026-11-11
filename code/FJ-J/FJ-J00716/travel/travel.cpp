#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string n,m;
	string a,b;
	cin>>n>>a>>m>>b;
	if(n==m){
		cout<<'1';
	}
	else{
		cout<<'0';
	}
	if(a[0]==b[0]&& a[1]==b[1]){
		cout<<'1';
	}else{
		cout<<'0';
	}
	if(a[2]<='C'&&b[2]<='C'||a[2]>'C'&&b[2]>'C'){
		cout<<'1';
	}
	else{
		cout<<'0';
	}
	if(a[2]==b[2]+1||a[2]==b[2]-1){
		cout<<'1';
	}else{
		cout<<'0';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
