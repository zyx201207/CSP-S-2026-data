#include<bits/stdc++.h>
using namespace std;
long long n,m,big;
long long a[200009];
int main(){
	freopen("and5.in","r",stdin);
	//freopen("and.out","w",stdout);
	cin>>n>>m; 
	for(int i=0;i<n;i++){
		cin>>a[i];
	}sort(a,a+n,greater<long long>());
	cout<<a[m];
	return 0;
}
