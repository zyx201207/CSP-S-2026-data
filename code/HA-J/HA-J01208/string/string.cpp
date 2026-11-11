#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
long long int a[N];
char b[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long int n, cnt = 0;
	string s = "";
	cin >> n;
	for(long long int i = 1; i <= n; i++){
		cin >> a[i] >> b[i];
		for(long long int j = 1; j <= a[i]; j++){
			s += b[i];
		}
	}
	long long int len = s.size();
	long long int i, j;
	for(i = 0; i < ceil(len /2);){
		for(j = len - 1; j > ceil(len / 2);){
			if(s[i] != s[j]){
				cnt++;
			}
			i++;
			j--;
		}
	}
	cout << cnt;
	return 0;
}
