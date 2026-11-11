// GZ-J00629 µËÍûÔÆ
#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a[0]==c[0]&&a[1]==c[1]){
		cout<<1;
		if(b[0]==d[0]&&b[1]==d[1]){
			cout<<1;
			int x=b[2]-'A';
			int y=d[2]-'A';
			if(x+y==7){
				cout<<11;
			}else if(x+y<=3&&x<3&&y<3){
				cout<<1;
				if(x+y==1||x+y==3){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
}
