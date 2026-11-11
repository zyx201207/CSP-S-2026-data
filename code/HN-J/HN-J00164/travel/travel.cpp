#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define pi pair<int,int>
#define mini pi,vector<pi>,greater<pi>
#define p_q priority_queue
#define fs first
#define se second
using namespace std;
const ll N = + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;

string c1,c2,c3,c4;

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("travel.in","r",stdin); freopen("travel.out","w",stdout);

	cin >> c1 >> c2 >> c3 >> c4;
	
	if(c1 == c3){
		cout << 1;
		if(c2[0] == c4[0] and c2[1] == c4[1]){
			cout << 1;
			if((c2[2] < 'D' and c4[2] < 'D') or (c2[2] > 'C' and c4[2] > 'C')){
				cout << 1;
				if(abs(int(c2[2] - c4[2])) == 1) cout << 1;
				else cout << 0;
			}else cout << "00";
		}else{
			cout << "000";
		}
	}else cout << "0000";

	return 0;
}

