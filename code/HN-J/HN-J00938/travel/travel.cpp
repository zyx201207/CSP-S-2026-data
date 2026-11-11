#include<bits/stdc++.h>
#define int long long
//voidÄ©Î²Òª¼Óreturn;
using namespace std;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		string g1=s1.substr(0,2);
		string g2=s2.substr(0,2);
		if(g1==g2){
			cout<<1;
			if((s1[2]>'C' and s2[2]>'C') or (s1[2]<='C' and s2[2]<='C')){
				cout<<1;
				if(abs((int)s1[2]-s2[2])==1){
					cout<<1;
				}		
				else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
 
