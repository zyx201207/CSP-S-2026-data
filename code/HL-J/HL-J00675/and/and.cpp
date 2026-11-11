#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int a[10001];
int d[10000001];
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,maxx=0;
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
		
	cout<<a[n];
	return 0;
}
