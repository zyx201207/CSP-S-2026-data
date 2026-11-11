#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	cout<<a[n-m]<<endl;
	
	return 0;
}
