#include <bits/stdc++.h>
#define int long long
#define f(i,l,r) for(int i = l;i<=r;i++)

using namespace std;

const int N = 1e6 + 5;

int c1,s1,c2,s2 = 0;
char l1,l2;
char ch;
int read() {
	int sum = 0,f = 1;
	while(ch < '0' || ch > '9'){
		if(ch == '-')f = -1;
		ch = getchar();
	}
	while('0' <= ch && ch <= '9'){
		sum = sum * 10 + ch - 48;
		ch = getchar();
	}
	return sum * f;
}

int mp[135];

void init(){
	mp['A'] = 1;
	mp['B'] = 2;
	mp['C'] = 3;
	mp['D'] = 1e4 + 1;
	mp['E'] = 1e4 + 2;
}

signed main() {
//	freopen("travel5.in","r",stdin);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	init();
	
	ch = getchar();
	
	c1 = read();
	s1 = read();
	l1 = ch;
	c2 = read();
	s2 = read();
	l2 = ch;
//	cout << l1 << ' ' <<l2 <<endl;
	
	bool ans1 = (c1 == c2);
	bool ans2 = (ans1 && (s1 == s2));
	bool ans3 = (ans2 && (abs(mp[l1] - mp[l2]) < 1e3));
	bool ans4 = (ans3 && (abs(mp[l1] - mp[l2]) == 1));
	
	cout << ans1  <<ans2 << ans3 <<ans4 << endl;
	
	return 0;
} 
