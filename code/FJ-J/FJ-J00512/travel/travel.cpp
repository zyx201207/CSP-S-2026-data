#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<"1";
		if(b[0]==d[0]&&b[1]==d[1]){
			cout<<"1";
			if((b[2]-'A'<=2&&d[2]-'A'<=2)||(b[2]-'A'>=3&&d[2]-'A'>=3)){
				cout<<"1";
				int b2=b[2]-'A',d2=d[2]-'A';
				if(b2<d2) swap(b2,d2);
				if((b2-d2==1||b2-d2==-1)&&b2!=3) cout<<"1";
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
}
