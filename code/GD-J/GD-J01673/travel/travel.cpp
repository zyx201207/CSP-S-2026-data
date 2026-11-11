#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<"1";
		int x=(b[0]-48)*10+(b[1]-48);
		int y=(d[0]-48)*10+(d[1]-48);
		if(x==y){
			cout<<"1";
			if(b[2]<=67&&d[2]<=67||b[2]>=68&&d[2]>=68){
				cout<<"1";
				if(abs((int)(b[2])-(int)(d[2]))==1||b[2]=='D'&&d[2]=='F'||b[2]=='F'&&d[2]=='D'){
					cout<<"1";
				}
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
