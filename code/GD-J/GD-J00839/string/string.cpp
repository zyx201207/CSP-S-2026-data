#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 50;
int n;
string p;
string s;
long long k;
long long len = 0;
struct node{
	long long shu;
	string zf;
};
node a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	string last = "";
	bool ok = false;
	for(int i = 1; i <= n; i++){
		cin >> k >> p;
		a[i].shu = k;
		a[i].zf = p;
		len += k;
		if(i == 1) last = p;
		else{
			if(last != s){
				ok = true;
				last = p;
			}
		}
	}
	
	if(ok == false) cout << 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= a[i].shu; j++){
			s += a[i].zf;
		}
	}
	string s1 = s;
	reverse(s.begin(),s.end());
	int len_2 = len / 2;
	int cnt = 0;
	for(int i = 0; i < len_2; i++){
		if(s1[i] != s[i]){
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}
