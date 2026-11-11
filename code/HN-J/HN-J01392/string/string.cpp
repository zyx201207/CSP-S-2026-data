#include <bits/stdc++.h>
using namespace std;
long long n,lengh;
//vector<long long> a;
//vector<char> c;
string s,w;
/*struct node{
	int i,step;
	node(int a,int b){
		i = a;
		step = b;
	} 
}*/
void init(){
	cin >> n;
	for(long long i = 0;i < n;++i){
		long long x;
		char y;
		cin >> x >> y;
		//a.push_back(x);
		//c.push_back(y);
		lengh +=  x;
		while(x--)s += y;
	}
} 
void solve(){
	long long ans = 0;
	for(long long i = 0;i < lengh / 2 + lengh % 2;++i){
		long long j = lengh - i - 1;
	 	if(s[i] != s[j])++ans; 
	}
	cout << ans;
}
int main(){
 	freopen("string.in","r",stdin);
	freopen("string.ans","w",stdout);
 	init();
 	solve();
 	return 0;
}
