#include<bits/stdc++.h>
using namespace std;
	string a;
	string b;
	string c;
	string d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a[1]==c[1]){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(b[1]==d[1]){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(b[1]==d[1]&&b[2]>=100&&d[2]>=100){
		cout<<"1";
	}else{
		if(b[1]==d[1]&&b[2]<=99&&d[2]<=99){
			cout<<"1";
		}else{
			cout<<"0";
		} 
	}
	if(b[2]==d[2]+1||b[2]==d[2]-1||b[1]==d[1]-1||b[1]==b[1]+1){
		cout<<"1";
	}else{
		cout<<"0";
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
