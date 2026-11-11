//GZ-J00657 陈恩源 兴义市弘毅中学
#include<bits/stdc++.h>
using namespace std;
string a,b,a1,b1; 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>a>>b>>a1>>b1;
	if(a==a1){
		cout<<1;
	}
	else{
		cout<<"0000"<<'\n';
		return 0;
	}
	if(b[0]==b1[0]&&b[1]==b1[1]){
		cout<<1;
	}
	else{
		cout<<"000"<<'\n';
		return 0;
	}
	if((b[2]>='A'&&b[2]<='C'&&b1[2]>='A'&&b1[2]<='C')||(b[2]>='D'&&b[2]<='F'&&b1[2]>='D'&&b1[2]<='F')){
		cout<<1;
	}
	else{
		cout<<"00"<<'\n';
		return 0;
	}
	if(b[2]-1==b1[2]||b[2]+1==b1[2]){
		cout<<1<<'\n';
	}
	else{
		cout<<0<<'\n';
	}
	return 0;
}
