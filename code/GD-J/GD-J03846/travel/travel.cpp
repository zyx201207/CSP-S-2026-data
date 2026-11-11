#include<bits/stdc++.h>
using namespace std;
string a,b,c,d,ans;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a;
	cin>>b;
	cin>>c;
	cin>>d;
	if(a==c){
		char a1=b[0],a2=b[1];
		char b1=d[0],b2=d[1];
		if(a1==b1&&a2==b2){
			a1=b[2];
			b1=d[2];
			if((a1<='C'&&b1<='C')||(a1>='D'&&b1>='D')){
				if(a1+1==b1||b1+1==a1){
					ans="1111";
				}
				else{
					ans="1110";
				}
			}
			else{
				ans="1100";
			}
		}
		else{
			ans="1000";
		}
	}
	else{
		ans="0000";
	}
	for(int i=0;i<4;i++){
		cout<<ans[i];
	}
	return 0;
}
