#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> a >> b >> c >> d;
	if(a == c){
		string p1 = "",p2 = "";
		for(int i = 0;i < 2;i++){
			p1 += b[i];
			p2 += d[i];
		}
		if(p1 == p2){
			char p3,p4;
			p3 = b[b.size() - 1];
			p4 = d[d.size() - 1];
			if(p3 <= 'C' && p3 >= 'A'){
				if(p4 <= 'C' && p4 >= 'A'){
					int a1 = p3 - 'A',a2 = p4 - 'A';
					if(abs(a1 - a2) == 1) cout << "1111";
					else cout << "1110";
				}else
					cout << "1100";
			}else{
				if(p4 == 'F' || p4 == 'D'){
					if(p3 == 'F' && p4 == 'D') cout << "1111";
					else if(p3 == 'D' && p4 == 'F') cout << "1111";
					else cout << "1110";
				}else{
					cout << "1100";
				}
			}
		}else
			cout << "1000";
	}else
		cout << "0000";
	return 0;
}
// 02 01A 02 01B
