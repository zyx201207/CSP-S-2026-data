#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    int n,m;
	cin >> n >> m;
	int a[n+1];
	long long sum=0;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	cout << a[(n+1)/2];
	return 0;
}
