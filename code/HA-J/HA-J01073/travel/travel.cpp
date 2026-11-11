#include <bits/stdc++.h>
using namespace std;
string a,b,c,d,ans="0000";
int x,y,z;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		ans[0]='1';
	}
	if(ans[0]=='1'){
		if(b[0]==d[0]&&b[1]==d[1]){
			ans[1]='1';
		}
	}
	if(ans[1]=='1'){
		if('A'<=b[2]&&b[2]<='C'){
			x=1;
		}else{
			x=0;
		}
		if('A'<=d[2]&&d[2]<='C'){
			y=1;
		}else{
			y=0;
		}
		if(x==y){
			ans[2]='1';
		}
	}
	if(ans[2]=='1'){
		if(x==1){
			if(b[2]!='B'&&d[2]!='B'){
				ans[3]='0';
			}else{
				ans[3]='1';
			}
		}else if(x==0){
			ans[3]='1';
		}
	}
	cout<<ans;
	return 0;	
}
