#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <set>
#include <stack>
#include <queue>
#include <bits/stdc++.h>


#define ll long long

using namespace std;



bool ss(string a, string c) {
	for(int i = 0; i < 2; i++) {
		if(a[i] == c[i]) {
			continue;
		}
		else {
			return false;
		}
	}
	return true;
}
bool ps(string b, string d) {
	if(b[2] >= 'A' && b[2] <= 'C' && d[2] >= 'A'&&d[2] <= 'C') {
		return true;
	}
	else if(b[2] >= 'D' && b[2] <= 'F' && d[2] >= 'D'&&d[2] <= 'F') {
		return true;
	}
	else {
		return false;
	}
}

bool cs(string b, string d) {
	if(b[2] >= 'A' && b[2] <= 'C' && d[2] >= 'A'&&d[2] <= 'C') {
		if (b[2] == d[2] - 1 || b[2] == d[2] + 1) {
			return true;
		}
		else {
			return false ;
		}
		
	}
	else if(b[2] >= 'D' && b[2] <= 'F' && d[2] >= 'D'&&d[2] <= 'F') {
		if (b[2] == d[2] - 2 || b[2] == d[2] + 2) {
			return true;
		}
		else {
			return false ;
		}
	}
}

string a, b, c, d;



int main()
{
	
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> a >> b >> c >> d;
	
	if(ss(a, c)) {
		cout << 1;
	}
	else {
		cout << 0;
	}
	if(ss(b, d) && ss(a, c)) {
		cout << 1;
		
	}
	else {
		cout << 0;
	}
	
	if(ss(a, c) && ss(b, d) && ps(b, d)) {
		cout << 1;
		
	}
	else {
		cout << 0;
	}
	
	if(ss(a, c) && ss(b, d) && ps(b, d) && cs(b, d)) {
		cout << 1;
		
	}
	else {
		cout << 0;
	}
	
	
	
	
	return 0;
	
	
}