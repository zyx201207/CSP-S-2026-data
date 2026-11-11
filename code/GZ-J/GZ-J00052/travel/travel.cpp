//GZ-J00052 贵阳市第一中学 敖翔蓝天 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll hdl=0;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	if(b[0]==d[0]&&b[1]==d[1]){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	if((b[2]<='C'&&d[2]<='C')){
		cout<<1;
	}else if(b[3]>'C'&&d[3]>'C'){
		hdl=1;
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}
	if(hdl){
		cout<<1;
	}else{
		if(b[2]-d[2]==1||d[2]-b[2]==1){
			cout<<1;
		}else{
			cout<<0;
		}
	}
	return 0;
}
//8:40	正式开考
//9:00	AC
//胡大佬牛福！！ 
