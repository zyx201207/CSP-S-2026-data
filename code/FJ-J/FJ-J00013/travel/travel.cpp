#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

string c1,s1,c2,s2;

signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2){
		cout << "1";
		
		string t = s1.substr(0,2);
		int id1 = stoll(t);
		char seat1 = s1[2];
		t = s2.substr(0,2);
		int id2 = stoll(t);
		char seat2 = s2[2];

		if(id1 == id2){
			cout << "1";
			
			if((seat1<='C'&&seat2<='C') || (seat1>='D'&&seat2>='D')){
				cout << "1";
				
				bool flag = false;
				if(seat1=='D' && seat2=='F'){
					flag = true;
				}
				if(seat1=='F' && seat2=='D'){
					flag = true;
				}
				if((seat1<='C'&&seat2<='C') && abs((int)(seat1-seat2))==1){
					flag = true;
				}
				
				cout << (flag?"1":"0") << endl;
			}
			else{
				cout << "00";
			}
		}
		else{
			cout << "000";
		}
	}
	else{
		cout << "0000";
	}
	cout << endl;

	return 0;
}

