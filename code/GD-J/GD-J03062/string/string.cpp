#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6;
int n;
long long a[maxn];
char c[maxn],c1[maxn];
long long sum,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	long long k = 1;
	for(int i= 1;i <= n;i++){
		cin >> a[i];
		cin >> c[i];
		sum += a[i];
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= a[i];j++){
			c1[k] = c[i];
			k++;
		}
	} 
	for(long long i = 1;i <= sum/2;i++){
		if(c1[i] != c1[sum-i+1]) ans++;
	}
	cout << (long long)ans;
	return 0;
}
