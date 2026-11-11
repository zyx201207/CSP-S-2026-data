#include <bits/stdc++.h>
using namespace std;
char x,y;
int ca,cb,sa,sb;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>ca>>sa>>x>>cb>>sb>>y;
	if(ca!=cb){
		cout<<"0000";
	}
	else if(sa!=sb){
		cout<<"1000";
	}
	else if((x>='D'&&y<='C')||(x<='C'&&y>='D')){
		cout<<"1100";
	}
	else if(x!=y+1&&y!=x+1){
		cout<<"1110";
	}
	else cout<<"1111";
	return 0;
}