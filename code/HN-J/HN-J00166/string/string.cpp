#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int n,cnt;
string s,d;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		int a;
		char b;
		cin >> a >> b;
		while(a--){
			s += b;
		}
 	}d = s;
	reverse(s.begin(),s.end());
	for(int i = 0;i < s.size()/2+1;i++){
		if(s[i] != d[i]){
			cnt++;
		}
	}cout << cnt/2;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
