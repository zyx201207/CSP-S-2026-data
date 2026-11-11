#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;cin >> n >> m;
	for(int i = 0; i < n;i++) {
		cin >> a[i];
	}
	for(int i = 0;i < m;i++) {
		if(a[i] < a[i + 1]){
			if(a[i + 1]-a[i]<= m) {
				a[i] += a[i + 1];
				i+=a[i + 1] - a[i]-1;
			}
		}
		else if(a[i] > a[i + 1]){
			if(a[i]-a[i + 1]<= m) {
				a[i + 1] += a[i];
				i+=a[i] - a[i + 1]-1;
			}
		}
	}
	int h = 0;
	for(int i = 0;i < n;i++) {
		if(a[i]==a[i+1]){
			h++;
		}
	}
	cout << h+2;
	return 0;
} 

