#include <bits/stdc++.h>
using namespace std;
string L;
int n;
long long a[20005],s[20005];
char c[20005];
bool f;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i] >> c[i];
	} 
	
	s[1] = a[1];
	for(int i = 1;i <= n;i++){
		s[i] = s[i - 1] + a[i];
	}
	
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= a[i];j++){
			L += c[i];
		}
	}
	
	for(int i = 2;i <= n;i++){
		if(c[i] != c[i - 1]){
			f = 0;
			break;
		}
		else{
			f = 1;
		}
	}
	if(f){
		cout << 0;
		return 0;
	}
	f = 1;
	for(long long i = n;i >= n;i--){
		int l = 1;
		long long mid = l + (s[i] - l) / 2;
		for(long long j = l;j <= mid;j++){
			if(L[mid - j] != L[mid + j]){
				cout << mid - j << ' ';
				f = 0;
				break; 
			}
		}
		if(!f){
			break;
		}
	} 
	return 0;
} 
