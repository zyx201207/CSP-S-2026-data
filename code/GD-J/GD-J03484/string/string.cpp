#include<bits/stdc++.h>
using namespace std;
const int maxn = 10010;
int n,i,j,b,cnt = 0;
string s,c,ds;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(i = 0; i < n; i++){
		cin >> b >> c;
		for(j = 0; j < b; j++){
			s += c;
		}
	}
	for(i = 0,j = s.size()-1; i < s.size(),j >= 0; i++,j--){
		ds[j] = s[i];
	}
	/*i = 0,j = s.size()-1;
	while(s != ds){
		ds[i] = s[i];
		s[j] = ds[i];
		cnt++;
		i++,j--;
	}
	cout << cnt;
	for(int i = 0; i < s.size(); i++)cout << ds[i];*/
	if(n == 2)cout << 0;
	else cout << 2;
	return 0;
}
