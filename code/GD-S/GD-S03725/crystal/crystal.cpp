#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	cin >> n;
	int m;
	cin >> m;
	int crys[m];
	int tt = m;
	for(int i = 0;i<n;i++){
		cin >> crys[i];
		tt+=crys[i];
	}
	int ans = 0;
	int sum = n;
	int all = 0;
	for(int i = 0;i<n;i++){
		for(int j = 0;j!=i;j++){
			int a = (tt-crys[i]-crys[j])/(n-2);
			if(a>all) all = a;
		}
	}
	cout << n-2;	
	
	return 0;
}
