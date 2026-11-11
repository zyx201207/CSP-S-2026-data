#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	string a,b,c,d;
	char x,y;
	cin>>a>>b>>c>>d;
	x=b[2];y=d[2];
	if(a==c){
		cout<<1;
		if(b.substr(0,2)==d.substr(0,2)){
			cout<<1;
			if((x<='C'&&y<='C')||(x>='D'&&y>='D')){
				cout<<1;
				if((char(x+1)==y&&x!='C')||(char(y+1)==x&&y!='C')){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
