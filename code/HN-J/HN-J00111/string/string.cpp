#include<bits/stdc++.h>
using namespace std;
const int MAXN = 200005;
int a[MAXN];
string c[MAXN];
long long maxcn;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	bool small = true;
	for(int i=0;i<n;i++){
		cin >> a[i] >> c[i];
		if(a[i] > 500)small = false;
	}
	if(small){
		string s;
		for(int i=0;i<n;i++){
			for(int j=0;j<a[i];j++){
				s += c[i];
			}
		}
		int cnt = 0;
		for(int i=0;i<s.size()/2;i++){
			if(s[i] != s[s.size() - i - 1]){
				cnt++;
			}
		}
		cout << cnt;
	}
	else{
		string s;
		for(int i=0;i<n;i++){
			s += c[i];
		}
		int cnt = 0;
		for(int i=0;i<s.size()/2;i++){
			if(s[i] != s[s.size() - i - 1]){
				cnt++;
			}
		}
		bool t = true;
		for(long long i=1;i<=1000000000;i*=10){
			for(int j=0;j<n;j++){
				if(a[j] % i != 0){
					t = false;
				}
			}
			if(t) maxcn = i;
		}
		long long num = cnt*maxcn;
		cout << num;
	}
	return 0;
}
