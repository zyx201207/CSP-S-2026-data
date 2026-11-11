#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <ctime>
#include <cstdlib>
using namespace std;

typedef long long LO;
typedef pair<LO, int> PLI;
const int N = 5e5 + 3;
int n;
LO m, a[N], b[N], k[N], sum;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for(int i = 1;i <= n;++i){
		cin >> a[i];
		b[i] = a[i];
	}
	sort(b+1, b+n+1);
	for(int i = 2;i <= n;++i){
		k[i] = b[i] - b[i-1];
	}
	for(int i = 2;i <= n;++i){
		sum += (i-1)*k[i];
		if(m<sum){
			cout << i-1;
			break;
		}
	}
	if(m >= sum) cout << n;
	return 0;
}

