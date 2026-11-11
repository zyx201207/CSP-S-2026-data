#include <bits/stdc++.h> 
using namespace std;
long long n,x,l,r,sum;
string s,a,b;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	if(n == 1){
		cout << "0";
	}
	else if(n == 2){
		cin >> x >> a >> sum >> b;
		if(a == b) cout << 0;
		else if(sum == x)	cout << x;
		else cout << abs(sum - x);
	}
	else{
		for(int i = 1;i <= n;i++){
			cin >> x >> a;
			for(int j = 1;j <= x;j++)	s += a;
		}
		l = 0,r = s.size() - 1,sum = 0;
		for(int i = 0;i < s.size();i++){
			if(l > r)	break;
			if(s[l] != s[r])	sum++;
			l++,r--;
		}
		cout << sum;
	}
	return 0;
}
