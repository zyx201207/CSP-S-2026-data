#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 2e5 + 10;
int a[maxn];
char b[maxn];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++)
		cin >> a[i] >> b[i];
	int p1 = 1,p2 = n;
	int w1 = 0,w2 = 0;
	ll ans = 0;
	while(p1 < p2)
		if(a[p1] - w1 > a[p2] - w2){
			if(b[p1] != b[p2])ans += a[p2] - w2;
			w1 += a[p2] - w2;
			--p2;
			w2 = 0;
		}
		else if(a[p1] - w1 < a[p2] - w2){
			if(b[p1] != b[p2])ans += a[p1] - w1;
			w2 += a[p1] - w1;
			++p1;
			w1 = 0;			
		}
		else{
			if(b[p1] != b[p2])ans += a[p2] - w2;
			++p1,--p2;
			w1 = w2 = 0;
		}
	cout << ans;
}

