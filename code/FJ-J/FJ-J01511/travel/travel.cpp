#include <bits/stdc++.h>
using namespace std;
string ans;
int main(){
	freopen("travel","r",stdin);
	freopen("travel","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a[0]==c[0]&& a[1]==c[1]){
		ans+='1';
	}else{
		ans+='0';
	}
	if(b[0]==d[0]&& b[1]==d[1] && ans[0]=='1'){
		ans+='1';
	}else{
		ans+='0';
	}
	if((b[2]>='D' && d[2]>='D' || b[2]<='C' && d[2]<='C') && ans[1]=='1' && ans[0]=='1'){
		ans+='1';
	}else{
		ans+='0';
	}
	if((b[2]==d[2]+1 || b[2]==d[2]-1) && ans[2]=='1' && ans[0]=='1'){
		ans+='1';
	}else{
		ans+='0';
	}
	for(int i=0;i<=3;i++){
		cout<<ans[i];
	}
	return 0;
}
