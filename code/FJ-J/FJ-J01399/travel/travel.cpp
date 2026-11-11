#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c) {
		cout<<"1";
		int flag=0;
		for(int i=0; i<=1; i++) {
			if(b[i]!=d[i]) {
				flag=1;
				break;
			}
		}
		char s_1=b[2];
		char s_2=d[2];
		if(flag){
			cout<<"000";
		}else{
			cout<<"1";
			if(s_1<='C'&&s_2<='C'||(s_1=='D'&&s_2=='F')||(s_1=='F'&&s_2=='D')){
				cout<<"1";
				if(s_1<='C'&&s_2<='C'){
					if(abs(int(s_1)-int(s_2))==1) cout<<"1";
					else cout<<"0";
				}else{
					cout<<"1";
				}
			}else{
				cout<<"00";
			}
		}
	} else {
		cout<<"0000";
	}
	return 0;
}
