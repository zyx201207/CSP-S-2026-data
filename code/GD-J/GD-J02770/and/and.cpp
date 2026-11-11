#include<bits/stdc++.h>
using namespace std;
long long n,c,m,a[1000000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		cin>>a[i];
		c++;
	}sort(a,a+c);
	cout<<a[c/2];
	return 0;
} 
