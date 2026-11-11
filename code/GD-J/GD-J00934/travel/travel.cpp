#include<bits/stdc++.h>
#define in long long
using namespace std;
string x,y;
in a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>x>>b>>y;
	in xn,yn;
	xn=(x[0]-'0')*10+(x[1]-'0');
	yn=(y[0]-'0')*10+(y[1]-'0');
	if(a==b){
		cout<<1;
		if(xn==yn){
			cout<<1;
			if(x[2]<'D'&&y[2]<'D'||x[2]>'C'&&y[2]>'C'){
				cout<<1;
				if(x[2]==y[2]+1||x[2]+1==y[2]){
					cout<<1;
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
