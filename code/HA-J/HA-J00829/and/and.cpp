#include <bits/stdc++.h>
using namespace std;
long long arr[200005];
bool cmp(long long a,int b){
	return a>b;
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>arr[i];
	}
	sort(arr+1,arr+n+1);
	for(long long i=2 ;i<= m;i++){
		arr[i] and arr[i-1];
	}
	cout<<arr[m];
	return 0;
}
