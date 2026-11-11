#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int n,x = 1,ans;
char s[N];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin >> n;
	while(n--){
		int a;
		char b;
		cin >> a >> b;
		for(int i = x; i < x+a; i++) s[i] = b;
		x += a;
	}
	
	for(int i = 1; i <= (x+1)/2; i++){
		if(s[i] != s[x-i]) ans++;
	}
	
	cout << ans;
	return 0;
}
