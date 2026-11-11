#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n,a[N];
char c[N];
long long check(string s){
	long long sum = 0;
	long long j = n;
	for(long long i = 0;i < j;i++){
		
		j--;
		
		if(s[i] != s[j]){
			if(a[i] > a[j]){
				sum += a[j];
				a[i] -= a[j];
				i--;
			}else{
				sum += a[i];
				a[j] -= a[i];
				j++;
			}
		}else{
			if(a[i] > a[j]){
				a[i] -= a[j];
				i--;
			}else{
				a[j] -= a[i];
				j++;
			}
		}
	}
	return sum;
}

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 0;i < n;i++){
		cin >> a[i] >> c[i];
	}
	cout << check(c);
	return 0;
} 
