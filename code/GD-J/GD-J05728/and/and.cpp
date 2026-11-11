#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	long long a[100000];
	for(int i=0;i<=n-1;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	cout<<a[n-1];
	fclose(stdin);
	fclose(stdout);
}
