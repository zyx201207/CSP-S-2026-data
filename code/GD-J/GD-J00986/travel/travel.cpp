#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		string l1=s1.substr(0,2),l2=s2.substr(0,2);
		if(l1==l2){
			cout<<1;
			int x1=s1.back()-'A',x2=s2.back()-'A';
			if((x1>2)==(x2>2)){
				cout<<1;
				if(x1<=2){
					if(abs(x1-x2)==1) cout<<1;
					else cout<<0;
				}else{
					cout<<1;
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
}
