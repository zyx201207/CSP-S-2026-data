#include <bits/stdc++.h>
using namespace std;
int x,y;
string _1,_2;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>x>>_1>>y>>_2;
	if(x==y){
		cout<<"1";
		if(_1[0]==_2[0] && _1[1]==_2[1]){
			cout<<"1";
			if((_1[2]<='C' && _2[2]<='C')||(_1[2]>'C' && _2[2]>'C')){
				cout<<"1";
				if(abs(int(_1[2]-_2[2]))<=1)cout<<"1";
				else cout<<"0";
			}else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
	return 0;
}
