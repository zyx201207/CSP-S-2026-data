#include <bits/stdc++.h>
using namespace std;

int n,a[100005];
string s[100005],c[100005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	int i;
	for(i = 1;i <= n ;i++){
		cin >> a[i] >> c[i];
	}
	int q = 0;
	for(int j = 1 ;j <= n;j++){
		for(int k = 1;k <= a[j];k++){
			s[q] = c[j];
			q++;
		}		
	}
	int cnt = 0;
	for(int i = 0;i < q/2;i++){
		if(s[i] != s[q-i-1]){
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}
