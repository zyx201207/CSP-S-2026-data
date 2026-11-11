#include<bits/stdc++.h>
using namespace std;
string xrcx,xrzh,xxcx,xxzh;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>xrcx>>xrzh>>xxcx>>xxzh;
	if(xrcx==xxcx){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	if(xrzh[0]==xxzh[0]&&xrzh[1]==xxzh[1]){
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
	if(xrzh[2]=='D'||xrzh[2]=='F'){
		if(xxzh[2]=='D'||xxzh[2]=='F'){
			cout<<"1";
		}else{
			cout<<"00";
			return 0;
		}
	}else{
		if(xxzh[2]!='D'&&xxzh[2]!='F'){
			cout<<"1";
		}else{
			cout<<"00";
			return 0;
		}
	}
	int xrzhzyl,xxzhzyl;
	xrzhzyl=xrzh[2];
	xxzhzyl=xxzh[2];
	if(abs(xxzhzyl-xrzhzyl)==1){
		cout<<"1";
	}else{
		cout<<"0";
		return 0;
	}
	return 0;
}
