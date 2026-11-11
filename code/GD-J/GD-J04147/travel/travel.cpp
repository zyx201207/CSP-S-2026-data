#include<bits/stdc++.h>
using namespace std;
int main(){
	//ÒÑ×öÍê 
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a1;
	cin>>a1;
	string a;
	cin>>a;
	int b1;
	cin>>b1;
	string b;
	cin>>b;
	if(a1!=b1){
		cout<<"0000";
		return 0;
	}
	else cout<<'1';
	if(a[0]==b[0] && a[1]==b[1]){
		cout<<'1';
	}
	else{
		cout<<"000";
		return 0;
	}
	if((a[2]<='C' && b[2]<='C') || (a[2]>='D' && b[2]>='D')){
		cout<<'1';
	}
	else{
		cout<<"00";
		return 0;
	}
	if(abs(b[2]-a[2])==1){
		cout<<'1';
	}
	else{
		cout<<"0";
		return 0;
	}
	return 0;

}
