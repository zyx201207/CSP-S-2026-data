#include<bits/stdc++.h>
using namespace std;
int  n,m,a[100000];
int main(){
	ios::sync_with_stdio(0);
	cin.tie();
	cout.tie();
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
}
sort(a+1,a+n+1);
cout<<a[n-m];
	return 0;
} 
