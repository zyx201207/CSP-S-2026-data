#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<'1';
		if(b[0]==d[0]&&b[1]==d[1]){
			cout<<'1';
			int x=b[2]-'A',y=d[2]-'A';
			if((x<=2?1:0)^(y<=2?1:0)){
				cout<<"00\n";
			}
			else{
				cout<<'1';
				if(x>=3||y>=3||(x-y<=1&&y-x<=1)){
					cout<<"1\n";
				}
				else{
					cout<<"0\n";
				}
			}
		}
		else{
			cout<<"000\n";
		}
	}
	else{
		cout<<"0000\n";
	}
	return 0;
}