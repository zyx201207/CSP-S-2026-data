#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pait pair<int,int>
const int N = 1e5+7;
const int M = 21;
const int px = 131;
const int mod = 998244353;
const int Mod = 1e9+7;
int to_int(string x){
	int sum = 0;
	for(char c:x) sum = sum * 10 + c - '0';
	return sum;
}
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	string ss = s1.substr(0,2),tt = s2.substr(0,2);
	int x1 = to_int(ss),y1 = to_int(tt);
	int x2 = s1[2] - 'A' + 1,y2 = s2[2] - 'A' + 1;
	if(c1 == c2){
		cout<<"1";
		if(x1 == y1){
			cout<<"1";
			if((x2 <= 3 && y2 <= 3) || (x2 > 3 && y2 > 3)) cout<<"1";
			else cout<<"0";
		}
		else cout<<"00";
		if(x1 == y1 && abs(x2 - y2) <= 1 && (x2 != 3 && y2 != 4) && (x2 != 4 && y2 != 3)) cout<<"1"<<endl;
		else if(x2 == y2 && abs(x1 - y1) <= 1) cout<<"1"<<endl;
		else cout<<"0"<<endl;
	}
	else cout<<"0000";
	return 0;
}
