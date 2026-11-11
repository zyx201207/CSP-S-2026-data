#include <bits/stdc++.h>

using namespace std;

long long n,m,a[200005];

long long solve(int x,int depth){
	if(depth == 1){
		return a[x];
	}
	long long i_=x+1;
	for(int i=x+2;i <= n-depth+2; i++){
		if(a[i]&a[x] > a[i_]&a[x]){
			i_=i;
		}
	}
	long long k = solve(i_,depth-1);
	return k & a[x];
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	int p=0;
	for(int i=1;i <= n-m;i++){
		p = max(solve(i,m),p)
	}
	cout << p;
}
