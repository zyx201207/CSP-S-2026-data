#include<bits/stdc++.h>
using namespace std;
//HN-02278
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,n1[100000],m1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>n1[i];
	}
	sort(n1+1,n1+n+1);
	m1=n1[n];
	for(int i=n-1;i>=n-m;i--){
		m1=n1[i]&m1;
	}
	cout<<m1;
	return 0;
}
