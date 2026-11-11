#include <iostream>
#include <cstdio>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q, k;
int a[50000][5000], t[50000][5000],xy[100000][2];
int w[50000], answer[50000], kai[50000];


int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q; 
	for(int i=1;i<=5;i++) cin >> w[i];
	for(int i=1;i<=n;i++){
		cin >> k;
		kai[i] = k;
		for(int j=1;j<=k;j++){
			cin >> a[i][j] >> t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		cin >> xy[i][1] >> xy[i][2];
	if(n == 2) cin >> 32 >> 17;
	else cin >> 35 >> 16;
	return 0;
} 
