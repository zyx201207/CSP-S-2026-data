#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a!=c){
		cout<<"0000";
	}else{
		cout<<1;
		if(b[0]==d[0]&&b[1]==d[1]){
			cout<<1;
			char x=b[2],y=d[2];
			if(x>y){
				swap(x,y);
			}
			if(y<='C'||x=='D'){
				cout<<1;
				if(int(y-x)==1){
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
	}
	return 0;
}
