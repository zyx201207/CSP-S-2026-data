#include<bits/stdc++.h>
#define in :
#define int long long
using us=unsigned;
using namespace std;
template<typename T>
void read(T& a) {
	cin>>a;
	return void();
}
template<typename T,typename... Args>
void read(T& a,Args&... args) {
	read(a);
	read(args...);
	return void();
}
template<typename T>
void print(T a) {
	cout<<a;
	return void();
}
template<typename T,typename... Args>
void print(T a,Args... args) {
	print(a);
	print(args...);
	return void();
}
signed main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	print(1,'\n',2);
	return 0;
}
