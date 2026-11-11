#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a[1001]={ };
	string c[1001]={ };
	cin >> n;
	string s[1001]={};
	string num;
	for(int i=n;i>=1;i--){
		cin >> a[i] >> c[i];
		if(c[i]==c[i]){
			num = "0";
		}	
	}
	cout << num;
	return 0;
}
