#include<iostream>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string a,b,a1,b1;
	bool x=0,y=0,z=0;
	cin>>a>>a1>>b>>b1;
	if(a[0]==b[0]&&a[1]==b[1]){
		cout<<"1";
		x=1;
	}else cout<<"0";
	if(x&&a1[0]==b1[0]&&a1[1]==b1[1]){
		cout<<"1";
		y=1;
	}else cout<<"0";
	if(y&&(a1[2]>='D'&&b1[2]>='D'||a1[2]<='C'&&b1[2]<='C')){
		cout<<"1";
		z=1;
	}else cout<<"0"; 
	if(z&&b1[2]-a1[2]==1){
		cout<<"1";
	}else cout<<"0";
	return 0;
}
