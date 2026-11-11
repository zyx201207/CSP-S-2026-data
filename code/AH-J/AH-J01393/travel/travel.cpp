#include<bits/stdc++.h>
using namespace std;
string ta,tb,tc,td,ans;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>ta>>tb>>tc>>td;
	int cx,sx,cy,sy;
	char x=tb[2],y=td[2];
	cx=(ta[0]-'0')*10+(ta[1]-'0');
	sx=(tb[0]-'0')*10+(tb[1]-'0');
	cy=(tc[0]-'0')*10+(tc[1]-'0');
	sy=(td[0]-'0')*10+(td[1]-'0');
	if(cx==cy){
		ans[0]='1';
		if(sx==sy){
			ans[1]='1';
			if((x>='D'&&y>='D')||(x<='C'&&y<='C')){
				ans[2]='1';
				if(x+1==y||x-1==y)ans[3]='1';
			}
		}
	}
	for(int i=0;i<=3;i++){
		if(ans[i]=='1')cout<<ans[i];
		else cout<<'0';
	}
	return 0;
}
