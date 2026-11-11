#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <functional>
using namespace std;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,k;cin>>n>>k;
	
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1,greater<int>());
	cout<<a[k];
	return 0;
}
