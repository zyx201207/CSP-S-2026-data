#include<bits/stdc++.h>
using namespace std; 
long long qwe[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	long long ma = -1;
	long long sum = 0;
	cin >> n>>m;
	for(int i=1;i<=n;i++){
		cin >> qwe[i];
	}
	sort(qwe+1,qwe+n+1);
	cout << qwe[n-1] and qwe[n] ;
}
