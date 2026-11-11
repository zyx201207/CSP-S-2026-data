#include<bits/stdc++.h>
using namespace std;
int const mod=2e5+10;
long long a[mod];
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n,m;
	long long o;
	cin>>n>>m;
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	o=a[0];
	for(int i=1; i<m; i++){
		o=o&a[i];
	} 
	cout<<o;
	return 0;
} 
