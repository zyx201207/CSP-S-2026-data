#include<bits/stdc++.h>
using namespace std;

const int N=2e5+5;
int n,m,cat;
long long a[N];

int main () {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	cat=a[n];
	for(int i=n-1;i>n-m;i--){
		cat&=a[i];
	}
	cout<<cat;
	return 0;
} 
