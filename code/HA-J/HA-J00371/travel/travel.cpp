#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
string a,b,c,d;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie();
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<'1';
		if(b[0]==d[0]&&b[1]==d[1]){
			cout<<'1';
			if((b[2]<='C'&&d[2]<='C')||(b[2]>='D'&&d[2]>='D')){
				cout<<'1';
				if((b[2]<='C'&&d[2]<='C')){
					if(b[2]+1==d[2]||b[2]-1==d[2]){
						cout<<'1'<<endl;
					}
					else cout<<'0'<<endl;
				}
				else cout<<'1'<<endl;
			}
			else{
				cout<<"00"<<endl;
			}
		}
		else cout<<"000"<<endl;
	}
	else{
		cout<<"0000"<<endl;
	}
	return 0;
}
