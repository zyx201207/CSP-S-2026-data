#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,len = 0,ans = 0;
	string apt;
	cin >> n;
	for(int i = 0;i < n;i++){
		int bb = len;
		int k;
		char ch;
		cin >> k >> ch;
		len += k;
		for(int j = bb;j < len;j++){
			apt[j] = ch;
		}
	}
	for(int i = 0;i < len/2;i++){
		if(apt[i] != apt[len - i - 1]){
			ans++;
		}
	}
	cout << ans;
	return 0;
}
