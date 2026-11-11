#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

string tobinary(ll x){
	string ans = "";
	while(x){
		ans += char(x%2 + '0');
		x /= 2;
	}
	return ans;
}

struct Num{
	string bin;
	long long num;
	int len;
	int cnt1;
}a[200005];

int n,m;
ll ans;

int count1(string x){
	int cnt = 0;
	for(int i = 0;i < x.size();i++){
		if(x[i] == '1') cnt++;
	}
	
	return cnt;
}

bool cmp(Num x,Num y){
	if(x.len != y.len) return x.len > y.len;
	else return x.bin > y.bin;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i].num;
		a[i].bin = tobinary(a[i].num);
		a[i].len = a[i].bin.size();
		a[i].cnt1 = count1(a[i].bin);
	}
	
	sort(a+1,a+n+1,cmp);
	
	for(int i = 2;i <= n;i++){
		while(a[i].bin.size() < a[1].bin.size()){
			a[i].bin += '0';
		}
	}
	
	ans = a[1].num;
	for(int i = 2;i <= m;i++){
		ans = ans & a[i].num;
	}
	
	cout << ans << '\n';
	return 0;
}
