#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	//cout<<a<<endl<<b<<endl<<c<<endl<<d<<endl;
	if(a==c){
		cout<<1;
		if(b[0]==d[0] && b[1]==d[1]){
			cout<<1;
			char x=b[2],y=d[2];
			if((x<='C'&&y<='C')||(x>'C'&&y>'C')){
				cout<<1;
				if((abs(x-y)==1)||(x=='D'&&y=='F')||(x=='F'&&y=='D')){
					cout<<1;
				}
				else{
					cout<<"0";
				}
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	cout<<endl;
	return 0;
}

