#include <bits/stdc++.h>
using namespace std;
long long m,n,s = 0,l;
int a[1000001];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i = 0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	for(long long i = 0;i<n-m;i++){
		l = a[i];
		for(long long j = i;j<i+m-1;j++){
			l = l&a[i];
		}
		if(l>=s)s = l;
	}
	cout<<s;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
