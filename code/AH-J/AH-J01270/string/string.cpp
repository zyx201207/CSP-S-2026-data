#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
#define int long long
int ans = 0;
int n;

struct Node{
	long long a;
	char c;
};
Node cha[N];

signed main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);

	cin >> n;
	for (int i = 1; i<=n; i++){
		cin >> cha[i].a >> cha[i].c;
	}
	
	int l = 1, r = n;
	while (l <= r){
		int mina = min(cha[l].a, cha[r].a);
		if (cha[l].c != cha[r].c) ans += mina;
		
		cha[l].a -= mina, cha[r].a -= mina;
		if (cha[l].a == 0 and cha[r].a == 0) l++, r--;  //cha[l].a == cha[r].a
		else if (cha[r].a != 0)	l++;                    //cha[l].a < cha.[r].a
		else if (cha[l].a != 0) r--;	                //cha[l].a > cha.[r].a
	}
	cout << ans;
}
