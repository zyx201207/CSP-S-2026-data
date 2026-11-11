#include<bits/stdc++.h>
using namespace std;
int n,m,sum = 0;
int i;
int a[200010] = {},b[200010] = {};
int amax = 0;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(i = 0; i < n; i++){
		cin >> a[i];
	}
	for(int i = 0; i <= m; i++){
		for(int j = 0; j < n; j++){
			amax = max(amax,a[j]);
			if(amax == a[j]) sum = j;
		}
		b[i] = amax;
		amax = 0;
		a[sum] = 0;
	}
	cout << b[m-1];
	return 0;
}
