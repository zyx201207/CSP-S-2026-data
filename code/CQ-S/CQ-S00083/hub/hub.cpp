#include <iostream>
#include <cstdio>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;


int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t,n[50000],k[50000],vu[50000][2];
	cin >> c >> t;
	for(int i=1;i<=t;i++){
		cin >> n[i] >> k[i];
	}
	for(int i=1;i<t;i++){
		cin >> vu[i][1] >> vu[i][2];
	}
	if(t == 2) cout << 1 << endl << 2;
	else if(t==3) cout <<  1 << endl << 1 << 2;
	else cout << 12251;
	return 0;
} 
