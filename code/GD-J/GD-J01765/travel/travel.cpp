#include<bits/stdc++.h>
using namespace std;
#define int long long
string a,b,c,d;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<1;
		if(b[0]==d[0]&&b[1]==d[1]){
			cout<<1;
			int x=b[2]-'A',y=d[2]-'A';
			if(x<3&&y<3){
				cout<<1;
				if(abs(x-y)==1){
					cout<<1;
				}else{
					cout<<0;
				}
			}else if(x>=3&&y>=3){
				cout<<1<<1;
			}else{
				cout<<0<<0;
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
