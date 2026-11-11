#include<bits/stdc++.h>
using namespace std;
#define int long long
string a,b,c,d;
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> a >> b >> c >> d;
    if(a==c){
		if(b[0]==d[0]&&b[1]==d[1]){
			if((b[2]-'A'<3&&d[2]-'A'<3)||(b[2]-'A'>=3&&d[2]-'A'>=3)){
				if((b[2]-'A'<3&&d[2]-'A'<3&&abs(b[2]-d[2])==1)||(b[2]-'A'>=3&&d[2]-'A'>=3&&abs(b[2]-d[2])==2)){
					cout << "1111";
				}else{
					cout << "1110";
				}
			}else{
				cout << "1100";
			}
		}else{
			cout << "1000";
		}
	}else{
		cout << "0000";
	}
    return 0;
}
