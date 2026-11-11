#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[200010];
//fz2021 
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
    int b=a[n-1];
	for(int i=1;i<m;i++){
		b=b&a[n-i-1];
		
	}
	cout<<b;

	
	
	

	
		            	

	
	
	
	
	return 0;
}

