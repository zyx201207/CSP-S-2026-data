#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool f1,f2,f3;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2){
		cout << 1;
		f1 = true;
	}else cout << 0;
	if (f1){
		string sub1 = s1.substr(0,2);
		string sub2 = s2.substr(0,2);
		if (sub1 == sub2){
			cout << 1;
			f2 = true;
		}else cout << 0;
	}else cout << 0;
	char dis1 = s1[s1.size() - 1];
	char dis2 = s2[s2.size() - 1];
	if (f1 && f2){
		if (dis1 == 'D' && dis2 == 'C' || dis1 == 'C' && dis2 == 'D') cout << 0;
		else{
			cout << 1; f3 = true;
		}
	}else cout << 0;
	if (f1 && f2 && f3){
		if (dis1 == 'D' && dis2 == 'C' || dis1 == 'C' && dis2 == 'D') cout << 0;
		else if (abs(dis1 - dis2) <= 1){
			 cout << 1;
		}else cout << 0;
	}else cout << 0;
	return 0;
}


