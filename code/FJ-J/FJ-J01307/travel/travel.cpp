#include <bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main (){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a >> b >> c >> d;
	string ans = "";
	if(a == c){
		ans += '1';
		string t1 = b.substr(0,2);
		string t2 = d.substr(0,2);
		if(t1 == t2){
			ans += '1';
			char c1 = b[2];
			char c2 = d[2];
			int tttt1;
			int tttt2;
			if(c1 == 'A' || c1 == 'B' || c1 == 'C') tttt1 = 1;
			else tttt1 = 2;
			if(c2 == 'A' || c2 == 'B' || c2 == 'C') tttt2 = 1;
			else tttt2 = 2;
			if(tttt1 == tttt2){
				ans += '1';
				if((c1 == 'A' && c2 == 'B')||
				   (c1 == 'B' && c2 == 'A')||
				   (c1 == 'C' && c2 == 'B')||
				   (c1 == 'B' && c2 == 'C')||
				   (c1 == 'D' && c2 == 'E')||
				   (c1 == 'E' && c2 == 'D') ){
				   		ans += '1';
				   		cout << ans;
				   }else{
				   		cout << "1110";
				   }
			}else{
				cout <<"1100";
			} 
		}else{
			cout << "1000";
		}
	}else{
		cout <<"0000";
	}
	return 0;
}
