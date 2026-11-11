#include <bits/stdc++.h>
using namespace std;

int n;
long long len,sum;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	string s=" ";
	for(int i = 1;i <= n;i++){
		int a;
		char c;
		cin >> a >> c;
		len+=a;
		for(int j = 1;j <= a;j++){
			s+=c;
		}
	}
	for(int i = 1;i <= len/2;i++){
		if(s[i]!=s[len-i+1]){
			sum++;
		}
	}
	cout << sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
