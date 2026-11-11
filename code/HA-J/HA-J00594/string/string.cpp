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

const int N = 2e5 + 10;

ll n;

int a[N];
char c[N];

bool cmp(){
	for(int i=2;i<=n;i++){
		if(c[i] != c[i-1]){
			return false;
		}
	}
	return true;
}

bool cnp(){
	for(int i=2;i<=n;i++){
		if(a[i] != a[i-1]){
			return false;
		}
	}
	return true;
}
ll ans;

int main()
{
	
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	
	if(cmp()){
		cout<<0;
		return 0;
	}
	if(cnp()){
		if(n%2==0){
			for(ll i = 1, j = n; i <= n/2, j > n/2; i++, j--){
				if(c[i] != c[j]){
					ans+=a[i];
				}
			}
		}
		else {
			for(ll i = 1, j = n; i <= n/2, j > (n/2) + 1; i++, j--){
				if(c[i] != c[j]){
					ans+=a[i];
				}
			}
		}
		cout<<ans;
		return 0;
	}
	
	
	cout << 0;
	
	
	
	
	
	
	
	
	return 0;
	
	
}