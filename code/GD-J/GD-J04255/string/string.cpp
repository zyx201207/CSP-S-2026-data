#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Mymap{
	ll geshu;
	char zifu;
}; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n;
	cin >> n;
    vector<Mymap> a;
    for(ll i = 0;i < n;i++){
    	ll A;
		char c;
    	cin >> A >> c;
    	struct Mymap Node;
    	Node.geshu = A;
    	Node.zifu = c;
    	a.push_back(Node);
	}
	ll len = a.size();
	if(n <= 1){
		cout << 0;
		return 0;
	}
	ll ans = 0,lentwo = len;
	if(len % 2 == 0) len = len / 2;
	else len = len / 2 + 1;
	for(ll i = 0;i < len;i++){
		if(a[i].zifu != a[lentwo - i - 1].zifu){
			ans += min(a[i].geshu,a[len-i-1].geshu);
		}
	}
	cout << ans;
	return 0;
}
