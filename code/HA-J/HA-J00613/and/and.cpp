#include<bits/stdc++.h>
using namespace std;
long long int n, m,a[1000000];
int main(){
  	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n-1);
	cout<<a[n-2];


	return 0;
}

