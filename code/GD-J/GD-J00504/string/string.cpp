#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cassert>
using namespace std;

const int N = 200005;
int n;
vector<pair<long long,char>> a;
long long s1[N];
long long getl(int id){ return s1[id-1] + 1; }
long long getr(int id){ return s1[id]; }
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	a.emplace_back(0ll,'?');
	cin >> n;
	for(int i = 1;i <= n;i++){
		long long A;char C;
		cin >> A >> C;
		if(C == a.back().second) a.back().first += A;
		else a.emplace_back(A,C);
	}
	n = a.size() - 1;
	long long s = 0;
	for(int i = 1;i <= n;i++) s += a[i].first,s1[i] = s1[i-1] + a[i].first;
	long long ans = 0;
	long long ptr = 1,lid = 1,rid = n;
	while(1){
		if(lid == rid) break;
		long long L = ptr,R = s - ptr + 1;
		if(getr(lid) - L + 1 > R - getl(rid) + 1){
			ans += (a[lid].second != a[rid].second) * (R - getl(rid) + 1);
			ptr += (R - getl(rid) + 1);
			rid--;
		}
		else{
			ans += (a[lid].second != a[rid].second) * (getr(lid) - L + 1);
			ptr += (getr(lid) - L + 1);
			lid++;
		}
	}
	cout << ans;
	return 0;
}