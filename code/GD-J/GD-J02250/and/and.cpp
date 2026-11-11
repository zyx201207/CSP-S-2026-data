#include <bits/stdc++.h>
using namespace std;
long long a[100000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	
	
	int mb=a[n-m];
	cout<<mb;
	 
	return 0;
}
