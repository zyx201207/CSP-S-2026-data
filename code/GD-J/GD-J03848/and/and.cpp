#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m;
int a[N];
int main(){
	freopen("and.out","w",stdout);
	freopen("and.in","r",stdin);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	cout<<a[n-m+1];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
