//GZ-J00409 遵义市第四中学 魏云藩 
#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int a = 0,b = 0,c = 0,ans = 0,lon = 0;
	string str = "";
	cin >> a;
	string s[100010]={};
	for (int i = 0;i < a;i++){
		cin >> b >> str;
		lon += b;
		for (int j = 0;j < b;j++){
			s[c]=str;
			c++;
		}
	}
	for (int i = 0;i < lon/2;i++){
		if (s[i] == s[lon-i-1]){
			continue;
		}
		else{
			ans += 1;
		}
	}
	cout << ans;
	return 0;
}

