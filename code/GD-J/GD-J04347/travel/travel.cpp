#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
char ans[4]={'0','0','0','0'};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		ans[0]='1';
	}else{
		cout<<ans;
		return 0;
	}
	if(b[0]==d[0]&&b[1]==d[1]){
		ans[1]='1';
	}else{
		cout<<ans;
		return 0;
	}
	if(b[2]-'D'<0&&d[2]-'D'<0||b[2]-'D'>=0&&d[2]-'D'>=0){
		ans[2]='1';
	}else{
		cout<<ans;
		return 0;
	}
	if(b[2]-d[2]==1||d[2]-b[2]==1){
		ans[3]='1';
	}else{
		cout<<ans;
		return 0;
	}
	cout<<ans;
	return 0;
}
