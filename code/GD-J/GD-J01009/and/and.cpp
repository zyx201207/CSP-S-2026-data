#include <bits/stdc++.h>
#include <iostream>
#include <string>

using namespace std;

typedef long long ll;
#define int ll
const int N = 2e5 + 10;
//-static
int n , m;

priority_queue<int> q;
signed main(){
	freopen( "and.in" , "r" , stdin );
	freopen( "and.out" , "w" , stdout );
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for( int i = 1 ; i <= n ; i++ ){
		int num;
		cin >> num;
		q.push(num);
	}
	int tmp = 0x3f3f3f3f3f , cnt = 0;
	while( !q.empty() ){
		cnt++;
		int p = q.top();
		q.pop();
		if( tmp == p ) cnt--;
		if( cnt >= m ){
			cout << p;
			return 0;
		}
	}
	return 0;
}
