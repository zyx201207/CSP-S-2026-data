#include<bits/stdc++.h>
using namespace std;
#define ll long long
string sa1,sa2,sb1,sb2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>sa1>>sa2>>sb1>>sb2;
	if(sa1==sb1){
		cout<<'1';
		if(sa2[0]==sb2[0]&&sa2[1]==sb2[1]){
			cout<<'1';
			int a=sa2[2]-'A',b=sb2[2]-'A';
			if((a<=2&&b<=2)||(a>2&&b>2)){
				cout<<'1';
				if(abs(a-b)==1) cout<<'1';
				else cout<<"0";
			}else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
	return 0;
}
