#include <bits/stdc++.h>
using namespace std;
long long n,a[100005],x = 0,c;
char b[100005];
string s;
int main(){
	freopen("stringin","r",stdin);
	freopen("stringout","w",stdout);
	cin >> n;
	for(int i = 0;i < n;i++){
		cin >> a[i] >> b[i];
		for(int j = 0;j < a[i];j++){
			s += b[i];
		}
	}
	c = s.size();
	for(int i = 0;i < c/2;i++){
		if(s[i] != s[c-i-1]){
			x++;
		}
	}
	cout << x;
	return 0;
}	
