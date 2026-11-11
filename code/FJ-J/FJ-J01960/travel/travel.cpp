#include <bits/stdc++.h>
using namespace std;
char a[3],b[4],c[3],d[4];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a[0]==c[0]&&a[1]==c[1]){
		cout<<"1";
		if(b[0]==d[0]&&b[1]==d[1]){
			cout<<"1";
			if((b[2]<'D'&&d[2]<'D')||(b[2]>'C'&&d[2]>'C')){
				cout<<"1";
				if(b[2]-d[2]==1||b[2]-d[2]==-1){
					cout<<"1";
				}else{
					cout<<"0";
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
