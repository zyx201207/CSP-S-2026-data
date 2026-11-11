#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[100001], b[100001], c[100001];
bool Find(int num, int st, int ed){
	for(int i = st; i < ed; ++i)if(c[i] == num){return true;}
	return false;
}
signed main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	memset(b, -1, sizeof(b));
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; ++i)cin >> a[i];
	for(int i = 0; i < n; ++i){
		memset(c, 0, sizeof(c));
		int tail = 0, head = 0;
		for(int j = i; j < n; ++j){
			if(Find(a[j], head, tail)){
				int k = 0;
				while(c[k] != a[j])k++;
				tail = k;
				head = k;	
			}
			c[tail++] = a[j];
		}
		for(int i = head; i < tail; ++i)b[c[i]]++;
	}
	for(int i = 0; i < 100001; ++i){
		if(b[i] == -1)continue;
		cout << b[i] + 1 << " ";
	}
	return 0;
} 
