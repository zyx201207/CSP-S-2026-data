#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m;
long long a[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	cout<<a[n-m+1];
	return 0;
}

