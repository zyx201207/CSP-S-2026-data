#include<bits/stdc++.h>

using namespace std;

int n;
string s;
long long cnt = 0;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> n;
	long long a;char c;
	long long z = 1;
	for(int i = 1;i <= n;i++){
		cin >> a >> c;
		for(int j = 1;j <= a;j++){
			s[z] = c;
			z++;
		}
	}
	for(int i = 1;i <= n;i++){
		if(s[i] !=  s[z + 1 -i]){
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}