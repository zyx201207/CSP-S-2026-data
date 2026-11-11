#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn =2e5+10;
int n;
int num[maxn];
char a[maxn];
int main () {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++) {
		cin >> num[i] >> a[i];
	}
	int mx=INT_MAX;
	for(char i='a';i<='z';i++) {
		int sum=0;
		for(int j=1;j<=n;j++) {
			if(a[j]!=i) sum+=num[j];
		}
		mx=min(mx,sum);
	}
	cout << mx;
return 0;
} 
