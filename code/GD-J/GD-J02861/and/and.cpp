#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005];
bool cpp(long long a,long long b){
	return a<b;
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cpp);
	cout<<a[n-m];

	
	
}
