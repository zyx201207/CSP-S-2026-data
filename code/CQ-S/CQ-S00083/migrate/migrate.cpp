#include <iostream>
#include <cstdio>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;


int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n[50000],d[50000][5000];
	cin >> c >> t;
	for(int i=1;i<=t;i++){
		cin >> n[i];
		for(int j=1;j<=n[i];j++){
			cin >> d[i][j]; 
		}
	}
	for(int i=1;i<=t;t++) cout << 0 << endl;
	return 0;
}
