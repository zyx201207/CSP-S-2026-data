#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,a[10000]={0},m,sum=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	sum=a[n-1];
	for(int i=1;i<m;i++){
		sum&=a[n-1-i];
	}
	cout<<sum<<endl;
	return 0;	
} 
