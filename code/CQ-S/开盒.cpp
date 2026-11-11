#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using i128 = __int128;
using u128 = unsigned __int128;

mt19937_64 mrand((u64)random_device{}() << 32 ^ random_device{}() ^
	chrono::high_resolution_clock::now().time_since_epoch().count());
template<class T = i64,class T2>T rnd(T l,T2 r){
return uniform_int_distribution<T>(l,r)(mrand);}

int main (){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);

	for (int i = 1;i <= 688;i++){
		string s = to_string(i);
		reverse(s.begin(),s.end());
		s.resize(5,'0');
		reverse(s.begin(),s.end());
		if (!system(("diff -w CQ-S" + s + "/subway/subway.cpp 1.cpp > 1.txt").c_str())){
			cout << s << '\n';
		}
	}
}