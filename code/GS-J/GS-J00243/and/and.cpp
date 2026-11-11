#include<bits/stdc++.h>
using namespace std; 
long long a[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);	
	int m,n,p=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	p=a[n-1];
	for(int i=0;i<m;i++){
		p&=a[n-i-1];
	}
	cout<<p;
	return 0;
}
