#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
const ll N = 2e5 + 5;
const ll M = 1e5 + 5;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
struct node{
	int d;
	char c;
}a[N];
ll n,ans;
void work(){
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i].d >> a[i].c;
	}
	if(n == 1){
		cout << "0\n";
		return;
	}
	int l = 1,r = n,x = a[1].d,y = a[n].d;
	char cl = a[1].c,cr = a[n].c;
	while(l < r){
		if(x == y){
			if(cl != cr){
				ans += x;
			}
			l++,r--;
			x = a[l].d,y = a[r].d,cl = a[l].c,cr = a[r].c;
		}else if(x < y){
			if(cl != cr){
				ans += x;
			}
			y -= x;
			l++;
			x = a[l].d,cl = a[l].c;
		}else if(x > y){
			if(cl != cr){
				ans += y;
			}
			x -= y;
			r--;
			y = a[r].d,cr = a[r].c;
		}
	}
	cout << ans << "\n";
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int oT_To = 1;
	//cin >> oT_To;
	while(oT_To--){ work();}
	return 0;
}

