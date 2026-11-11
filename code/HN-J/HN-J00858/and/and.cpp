#include<bits/stdc++.h> 
using namespace std;
const int N=2e5+5;
long long n,m;
int a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<n%m+3;
	return 0;
}
