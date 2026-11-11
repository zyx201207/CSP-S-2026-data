#include <bits/stdc++.h>
using namespace std;


int n,m;
long long a[20000000];
long long b[20000000];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;

	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	cout<<a[n];
	
	return 0;
}


