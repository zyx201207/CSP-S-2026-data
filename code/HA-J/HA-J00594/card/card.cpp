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

const int N = 5e5 + 10;

int n, m;

int a[N];
int cnt;
int ans[N];

int main()
{
	
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;
	
	for(int i = 1; i <= n; i++) {
		cin>>a[i];
	}
	if(m == 1){
		cout << n;
		return 0;
	}
	
	for(int i = 1; i <= n; i++) {
		cout<< i << ' ';
	}
	
	
	
	
	
	return 0;
	
	
}