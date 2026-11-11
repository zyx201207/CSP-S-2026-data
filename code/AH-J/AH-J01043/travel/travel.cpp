#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c){
		if(b[0]==d[0]&&b[1]==d[1]){
			if(('A'<=b[2]&&b[2]<='C'&&'A'<=d[2]&&d[2]<='C')||('D'<=b[2]&&b[2]<='F'&&'D'<=d[2]&&d[2]<='F')){
				int o=int(b[2]),p=int(d[2]);
				int op=max(o,p)-min(o,p);
				if(op==1){
					cout<<"1111";
				}else{
					cout<<"1110";
				}
			}else{
				cout<<"1100";
			}
		}else{
			cout<<"1000";
			}
	}else{
		cout<<"0000";
	}
	return 0;
}
