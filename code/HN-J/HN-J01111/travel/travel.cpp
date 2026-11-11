#include<bits/stdc++.h>
using namespace std;
string s,s1,c,c1,ans;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s>>c>>s1>>c1;
	if(s==s1){
		ans+='1';
	}else{
		ans+='0';
	}
	if(ans[0]=='1'&&c[0]==c1[0]&&c[1]==c1[1]){
		ans+='1';
	}else{
		ans+='0';
	}
	if(ans[1]=='1'){
		if(c[2]<='C'&&c1[2]<='C'||c[2]>'C'&&c1[2]>'C'){
			ans+='1';
		}else{
			ans+='0';
		}
	}else{
		ans+='0';
	}
	if(ans[2]=='1'){
		if(c[2]+c1[2]!='C'+'D'&&c[2]==c1[2]+1||c[2]+c1[2]!='C'+'D'&&c1[2]==c[2]+1||c1[2]+c[2]=='D'+'F'){
			ans+='1';
		}else{
			ans+='0';
		}
	}else{
		ans+='0';
	}
	cout<<ans;
	return 0;
}
