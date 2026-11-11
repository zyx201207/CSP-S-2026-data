#include <iostream>
using namespace std;
string a,b,c,d;
int sa,sb;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<"1";
		if(b[0]==d[0]&&b[1]==d[1]){
			cout<<"1";
			int l=b[2]-'A',r=d[2]-'A';
			if((l<=2&&r<=2)||(l>=3&&r>=3)){
				cout<<"1";
				if(min(l,r)+1==max(l,r))cout<<"1";
				else cout<<"0";
			}else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
}
