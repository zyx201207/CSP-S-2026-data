#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
signed main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c_1,c_2;
	string s_1,s_2;
	cin>>c_1>>s_1>>c_2>>s_2;
	
	int zw_1,zw_2;
	int zm_1,zm_2;
	zw_1 = zw_2 = 0;
	if (s_1[0] == '1') zw_1 += (s_1[0] - '0') * 10;
	zw_1 += (s_1[1] - '0');
	zm_1 = s_1[2] - 'A';
	if (s_2[0] == '1') zw_2 += (s_2[0] - '0') * 10;
	zw_2 += (s_2[1] - '0');
	zm_2 = s_2[2] - 'A';
	
	bool T_1,T_2,T_3,T_4;
	T_1 = T_2 = T_3 = T_4 = 0;
	if (c_1 == c_2) T_1 = 1;
	if (T_1 && zw_1 == zw_2) T_2 = 1;
	if (T_2 && ((zm_1 <= 2 && zm_2 <= 2) || (zm_1 > 2 && zm_2 > 2))) T_3 = 1;
	if (T_3 && zm_2 - zm_1 == 1) T_4 = 1;
	cout<<T_1<<T_2<<T_3<<T_4;
	return 0;
}
/*
02 01C 02 01D
*/


