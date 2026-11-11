#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	scanf("%d %d",&n,&m);
	vector<int>a(n);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	sort(a.begin(),a.end());
	printf("%d",a[n-m]);
	return 0;
}

