//GZ-J00208 兴义市弘毅中学 廖颢云 
#include <bits/stdc++.h>
using namespace std;
string s,t;
char c,ch;
int n,x;
long long len2,len1,sumn;
bool b;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> len1 >> c;
		if(i == 1) ch = c;
		else if(ch != c)b = 1;
//		if(len + len1 > n / 2){
//			for(int i = len2;i <= n/2;i++){
//				s += c;
//			}
//		}
		for(int j = 1;j <= len1;j++){
			s += c;
		}
//		for(int j = 1;j <= len1;j++){
//			t += c;
//		}
		//len2 += len1;
	}
	if(b == 0){
		cout << 0;
		return 0;
	}
	for(int i = 0;i <= s.size()/2;i++){
		if(s[i] != s[n-i+1]){
			sumn++;
			//cout << s[i] << s[n-i+1];
		}
	}
	//if(s.size() % 2 == 0 && s[n/2] == s[n/2+1])sumn++; 
	cout << sumn;
	return 0;
}
