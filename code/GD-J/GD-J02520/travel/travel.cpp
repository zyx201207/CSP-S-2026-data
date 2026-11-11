#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d,ans;
	cin>>a>>b>>c>>d;
	if(a==c){
		ans[0]='1';
		if(b[0]==d[0]&&b[1]==d[1]){
			ans[1]='1';
			if((b[2]<='C'&&d[2]<='C')||(b[2]>='D'&&d[2]>='D')){
				ans[2]='1';
				if((b[2]+1==d[2])||(b[2]-1==d[2])){
					ans[3]='1';
				}else{
					ans[3]='0';
				}
			}else{
				ans[2]='0';
				ans[3]='0';
			}
		}else{
			ans[1]='0';
			ans[2]='0';
			ans[3]='0';
		}
	}else{
		ans[0]='0';
		ans[1]='0';
		ans[2]='0';
		ans[3]='0';
	}
	cout<<ans[0]<<ans[1]<<ans[2]<<ans[3];
	return 0;
} 
/*
in:02 01A 02 01B
out:1111
*/
